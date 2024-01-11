//Used in 893F
//you need to store all modifications
template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTree{
    vector<T> st;
    vector<int> lc, rc;
    int n, cnt, rt;
    SegmentTree(ll sz){ //queries * 40
        n = sz;
        st.resize(40*n);
        lc.resize(40*n);
        rc.resize(40*n);
        rt = build(1, n);
    }
    int build(int l, int r){
        int p = ++cnt;
        if(l == r){ st[p] = nullel(); return p; }
        lc[p] = build(l, (l+r)/2);
        rc[p] = build((l+r)/2 + 1, r);
        st[p] = op(st[lc[p]], st[rc[p]]); //some operation
        return p;
    }
    T query(int i, int j, int p, int l, int r){
        if(j < l || i > r) return nullel(); //identity element
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, lc[p], l, (l + r)/2), query(i, j, rc[p], (l + r)/2 + 1, r)); //some operation
    }

    T query(int i, int j, int p){
        return query(i, j, p, 1, n);
    }
    
    int update(int i, int value, int olp, int l, int r){
        if(i < l || i > r) return olp;
        int p = ++cnt;
        if(l == r) {st[p] = value; return p;}
        lc[p] = update(i, value, lc[olp], l, (l + r)/2);
        rc[p] = update(i, value, rc[olp], (l + r)/2 + 1, r);
        st[p] = op(st[lc[p]], st[rc[p]]);
        return p;
    }
    int update(int i, int value, int olp){
        return update(i, value, olp, 1, n);
    }
};

int op(int a, int b){
    return min(a, b);
}

int el(){
    return INF_INT;
}


//NO template :

const int N = 4e6; //n log n memory
int cnt = 0;
int st[N];
int lc[N], rc[N];
int n;

int build(int l = 1, int r = n){
    int p = ++cnt;
    if(l == r){ st[p] = INF_INT; return p; }
    lc[p] = build(l, (l+r)/2);
    rc[p] = build((l+r)/2 + 1, r);
    st[p] = min(st[lc[p]], st[rc[p]]); //some operation
    return p;
}

int query(int i, int j, int p, int l = 1, int r = n){
    if(j < l || i > r) return INF_INT; //identity element
    if(j >= r && i <= l) return st[p];
    return min(query(i, j, lc[p], l, (l + r)/2), query(i, j, rc[p], (l + r)/2 + 1, r)); //some operation
}

int update(int i, int value, int op, int l = 1, int r = n){
    if(i < l || i > r) return op;
    int p = ++cnt;
    if(l == r) {st[p] = value; return p;}
    lc[p] = update(i, value, lc[op], l, (l + r)/2);
    rc[p] = update(i, value, rc[op], (l + r)/2 + 1, r);
    st[p] = min(st[lc[p]], st[rc[p]]);
    return p;
}

