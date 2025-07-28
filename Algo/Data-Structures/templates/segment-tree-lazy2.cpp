//just testing, need to be improved and tested.
//test 1786E and maybe abc265g
//how to update lazy??
template<typename T, typename S, T (*op)(T, T), T (*nullel)()/*, T (*upd_lazy)(T, S)*/, S (*composition)(S, S), S (*id)()>
struct SegmentTreeLazy{
    vector<T> st;
    vector<S> lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, id());
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, nullel());
        lz.assign(4*n, id());
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    T query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return nullel();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, S val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, S val){
        update(i, j, val, 0, n-1, 1);
    }
    void push(int l, int r, int p){
        if(lz[p] != id()){
            // st[p] = upd_lazy(st[p], lz[p]);
            st[p] += (r - l + 1) * lz[p];
            if(l != r){
                lz[2*p] = composition(lz[2*p], lz[p]);
                lz[2 * p] = composition(lz[2*p+1], lz[p]); 
            } 
        }
    }
};

ll op_sum(ll a, ll b){
    return a + b;
}

ll null_sum(){
    return 0LL;
}

ll composition(ll old, ll nv){
    return old + nv;
}

ll null_lz(){
    return 0LL;
}

SegmentTreeLazy<ll, ll, op_sum, null_sum, composition, null_lz> st;