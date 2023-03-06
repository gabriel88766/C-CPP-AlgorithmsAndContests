#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//tested https://cses.fi/problemset/task/1651 with lazy
// O(log n) query and update, O(N) build
const int N = 2e5+6;
ll st[4*N], lz[4*N], cnt[4*N];
ll v[N];
int n;

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ st[p] = v[l]; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}

void push(ll l, ll r, int p){
    if(cnt[p]){ //0 can be assigned? change!
        st[p] += (r-l+1)*lz[p] + (((r-l+1)*(r-l+2))/2)*cnt[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
        if(l != r){
            lz[2 * p] += lz[p]; 
            lz[2 * p + 1] += lz[p] + (((l+r)/2)+1-l)*cnt[p];
            cnt[2*p] += cnt[p], cnt[2*p+1] += cnt[p];
        } 
        cnt[p] = lz[p] = 0;
    }
}

ll query(int i, int j, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return query(i, j, l, (l + r)/2, 2 * p) + query(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update(int i, int j, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) { lz[p] = l-i; cnt[p] = 1; push(l, r, p); return; }
    update(i, j, l, (l + r)/2, 2 * p);
    update(i, j, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    for(int i=1;i<=q;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            update(b,c);
        }else{
            cout << query(b,c) << "\n";
        }   
    }
}
