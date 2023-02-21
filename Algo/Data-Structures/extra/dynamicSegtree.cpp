//usually unnecessary
const int M = 18000000;
int st[M], lc[M], rc[M], cnt = 1; //216MB 
int v[200005];
int MAX_INT = 1e9;

void update(int pos, int add, int l = 1, int r = MAX_INT, int p = 1){
    if(l == r){ st[p] += add; return;}
    int mid = (l+r)/2;
    if(pos > mid){
        if(!rc[p]) rc[p] = ++cnt; 
        update(pos, add, mid+1, r, rc[p]);
    }else{
        if(!lc[p]) lc[p] = ++cnt;
        update(pos, add, l, mid, lc[p]);
    }
    st[p] = st[lc[p]] + st[rc[p]];
}

int query(int a, int b, int l = 1, int r = MAX_INT, int p = 1){
    if(p == 0) return 0; //node not created.
    if(b < l || a > r) return 0;
    if(l >= a && b >= r) return st[p];
    return query(a,b,l,(l+r)/2,lc[p]) + query(a,b,(l+r)/2+1,r,rc[p]);
}