//tested https://cses.fi/problemset/task/1648/ & 1649 & 1650 without lazy
//tested https://cses.fi/problemset/task/1651 with lazy
// O(log n) query and update, O(N) build
const int N = 2e5+6;
ll st[4*N], lz[4*N];
ll v[N];
int n;

void build(int l = 1, int r = n, int node = 1){
    if(l == r){ st[node] = v[l]; return; }
    build(l, (l+r)/2, 2 * node);
    build((l+r)/2 + 1, r, 2 * node + 1);
    st[node] = st[2 * node] + st[2 * node + 1]; //some operation
}

void push(int l, int r, int node){
    if(lz[node]){
        st[node] += (ll)(r - l + 1) * lz[node]; //operation applied in the range
        if(l != r){
            lz[2 * node] += lz[node]; // += if range sum, = if min or max, else -> think and code.
            lz[2 * node + 1] += lz[node];
        } 
        lz[node] = 0;
    }
}

ll query(int i, int j, int l = 1, int r = n, int node = 1){
    push(l, r, node);
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[node];
    return query(i, j, l, (l + r)/2, 2 * node) + query(i, j, (l + r)/2 + 1, r, 2 * node + 1); //some operation
}

void update(int i, int j, ll value, int l = 1, int r = n, int node = 1){
    push(l, r, node);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[node] = value; push(l, r, node); return;}
    update(i, j, value, l, (l + r)/2, 2 * node);
    update(i, j, value, (l + r)/2 + 1, r, 2 * node + 1);
    st[node] = st[2 * node] + st[2 * node + 1]; //some operation
}



