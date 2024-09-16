#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


ll sum(ll n){
    return (n * (n+1))/2;
}


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
    if(lz[p] != INF_LL){ //0 can be assigned? change!
        st[p] = (ll)(r - l + 1) * lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
        st[p] += ((ll)(r-l+1) * (r-l))/2;
        int m = (l + r)/2;
        if(l != r){
            lz[2 * p] = lz[p]; // += increment = update
            lz[2 * p + 1] = lz[p] + m - l + 1;
        } 
        lz[p] = INF_LL;
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
    if(l >= i && r <= j) {lz[p] = value + l - i; push(l, r, p); return;}
    update(i, j, value, l, (l + r)/2, 2 * p);
    update(i, j, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}




//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(lz, 63, sizeof(lz));
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    int q;
    cin >> q;
    ll ans = 0;
    for(int i=0;i<q;i++){
        ll t, g;
        cin >> t >> g;
        ll c = query(t, t);
        if(c == g) continue;
        else if(c > g){
            int p = t;
            for(int j=n/2;j>0;j>>=1){
                while(p - j > 0 && query(p-j,p-j) + t - p + j > g) p-=j;
            }
            ll bef = query(1, n);
            update(p, t, g - (t-p));
            ans += abs(bef - query(1, n));
        }else{
            int p = t;
            for(int j=n/2;j>0;j>>=1){
                while(p + j <= n && query(p+j,p+j) < g + (p+j - t)) p+=j;
            }
            ll bef = query(1, n);
            update(t, p, g);
            ans += abs(bef - query(1, n));
        }
    }
    cout << ans << "\n";
}
