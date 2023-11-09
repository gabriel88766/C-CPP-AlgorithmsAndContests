//tested https://cses.fi/problemset/task/1648/ & 1649 & 1650 without lazy
// O(log n) query and update, O(N) build
const int N = 2e5+6;
ll st[4*N];
ll v[N];
int n;

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ st[p] = v[l]; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}

ll query(int i, int j, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return query(i, j, l, (l + r)/2, 2 * p) + query(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update(int i, ll value, int l = 1, int r = n, int p = 1){
    if(i < l || i > r) return;
    if(l == r) {st[p] = value; return;}
    update(i, value, l, (l + r)/2, 2 * p);
    update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}


//first element less than y INF if not exist
int query2(int i, int j, int y, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return INF_INT; //identity element;
    if(l == r){
        if(st[p] <= y) return l;
        else return INF_INT;
    }
    if(st[2*p] <= y){
        int ans = query2(i, j, y, l, (l + r)/2, 2 * p);
        if(ans != INF_INT) return ans;
        else return query2(i, j, y, (l + r)/2 + 1, r, 2 * p + 1);
    }else if(st[2*p+1] <= y){
        return query2(i, j, y, (l + r)/2 + 1, r, 2 * p + 1);
    }else return INF_INT;
}

//with lazy prop, first element greater than or equal to y
int query(int i, ll y, int l = 0, int r = n-1, int p = 1){
    push(l, r, p);
    if(i > r) return INF_INT;
    if(l == r){
        if(st[p] >= y) return l;
        else return INF_INT;
    }
    push(l, (l+r)/2, 2*p);
    push((l+r)/2+1, r, 2*p+1);
    int ans = INF_INT;
    if(st[2*p] >= y){
        int ans = query(i, y, l, (l + r)/2, 2 * p);
        if(ans != INF_INT) return ans;
        else return query(i, y, (l + r)/2 + 1, r, 2 * p + 1);
    }else if(st[2*p+1] >= y){
        return query(i, y, (l + r)/2 + 1, r, 2 * p + 1);
    }else return INF_INT;
}


