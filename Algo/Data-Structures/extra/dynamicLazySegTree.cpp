//usually unnecessary
const int M = 15000000; //M > 60*N
int st[M], lz[M]
int lc[M], rc[M], cnt = 1; 
int v[200005];
int MAX_INT = 1e9;


void push(int l, int r, int p){
    if(lz[p]){
        if(!lc[p]) lc[p] = ++cnt;
        if(!rc[p]) rc[p] = ++cnt;
        st[p] += (ll)(r - l + 1) * lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
        if(l != r){
            lz[lc[p]] += lz[p]; // += increment = update
            lz[rc[p]] += lz[p];
        } 
        lz[p] = 0;
    }
}

void update(int i, int j, int add, int l = 1, int r = MAX_INT, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = add; push(l, r, p); return;}
    int mid = (l+r)/2;
    if(!lc[p]) lc[p] = ++cnt;
    update(i, j, add, l, mid, lc[p]);
    if(!rc[p]) rc[p] = ++cnt; 
    update(i, j, add, mid+1, r, rc[p]);
    st[p] = st[lc[p]] + st[rc[p]];
}

int query(int a, int b, int l = 1, int r = MAX_INT, int p = 1){
    push(l, r, p);
    if(b < l || a > r) return 0;
    if(l >= a && b >= r) return st[p];
    if(!lc[p]) lc[p] = ++cnt;
    if(!rc[p]) rc[p] = ++cnt; 
    return query(a,b,l,(l+r)/2,lc[p]) + query(a,b,(l+r)/2+1,r,rc[p]);
}