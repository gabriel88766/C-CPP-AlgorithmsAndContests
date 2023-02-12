//tested https://cses.fi/problemset/task/1648/ & 1649 & 1650 without lazy
//tested https://cses.fi/problemset/task/1651 with lazy
// O(log n) query and update, O(N) build
const int N = 2e5+6;
ll st[4*N], lz[4*N];
ll v[N];
int n;

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ st[p] = v[l]; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}

void push(int l, int r, int p){
    if(lz[p]){ //0 can be assigned? change!
        st[p] += (ll)(r - l + 1) * lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
        if(l != r){
            lz[2 * p] += lz[p]; // += increment = update
            lz[2 * p + 1] += lz[p];
        } 
        lz[p] = 0;
    }
}

ll query(int i, int j, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return query(i, j, l, (l + r)/2, 2 * p) + query(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update(int i, int j, ll value, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = value; push(l, r, p); return;}
    update(i, j, value, l, (l + r)/2, 2 * p);
    update(i, j, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}



