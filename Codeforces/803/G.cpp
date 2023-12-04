#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 10000000; //M > 60*N
int st[M], lz[M];
int lc[M], rc[M], cnt = 1; 
int v[100005];
int MAX_INT = 1e9;

ll sparse[100005][20];
int n;

void build(){
    for(int i=0;i<n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < 20; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

ll query1(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return min(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

int create(int l, int r){
    if(r - l >= n) return query1(0, n-1);
    if(r % n >= l % n) return query1(l % n, r % n);
    else return min(query1(l % n, n-1), query1(0, r % n));
}

void push(int l, int r, int p){
    if(lz[p]){
        if(!lc[p]) lc[p] = ++cnt;
        if(!rc[p]) rc[p] = ++cnt;
        st[p] = lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
        if(l != r){
            lz[lc[p]] = lz[p]; // += increment = update
            lz[rc[p]] = lz[p];
        } 
        lz[p] = 0;
    }
}

void update(int i, int j, int val, int l = 0, int r = MAX_INT, int p = 1){
    if(!st[p]) st[p] = create(l, r);
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
    int mid = (l+r)/2;
    if(!lc[p]) lc[p] = ++cnt;
    update(i, j, val, l, mid, lc[p]);
    if(!rc[p]) rc[p] = ++cnt; 
    update(i, j, val, mid+1, r, rc[p]);
    st[p] = min(st[lc[p]], st[rc[p]]);
}

int query(int a, int b, int l = 0, int r = MAX_INT, int p = 1){
    if(!st[p]) st[p] = create(l, r);
    push(l, r, p);
    if(b < l || a > r) return INF_INT;
    if(l >= a && b >= r) return st[p];
    if(!lc[p]) lc[p] = ++cnt;
    if(!rc[p]) rc[p] = ++cnt; 
    return min(query(a,b,l,(l+r)/2,lc[p]), query(a,b,(l+r)/2+1,r,rc[p]));
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int k;
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> v[i];
    build();
    st[1] = create(0, MAX_INT);
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int t, l, r, x;
        cin >> t >> l >> r;
        if(t == 1){
            cin >> x;
            update(l-1, r-1, x);
        }else{
            cout << query(l-1, r-1) << "\n";
        }
    }
}
