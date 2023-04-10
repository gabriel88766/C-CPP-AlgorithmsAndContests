#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("out", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> d(n+1), f(n+1);
        for(int i=1;i<=n;i++) cin >> f[i];
        for(int i=1;i<=n;i++) cin >> d[i];
        vector<ll> pow;
        for(int i=1;i<=n;i++) pow.push_back(f[i]*d[i]);
        sort(pow.begin(), pow.end());
        ll ans = n;
        for(int i=1;i<=n;i++){
            //suppose i is fixed;
            ll val = f[i]*d[i];
            vector<pair<ll,ll>> vc;
            for(int j=1;j<=n;j++){ 
                vc.push_back({(val/f[j])*f[j], j});
            }
            sort(vc.begin(), vc.end()); //O(n*n log n)
            int bp = 0;
            ll maxcur = prev(vc.end())->first;
            for(ll j = max(val-k, 1LL); j<= val; j++){ // O(n*k*log n)
                ll minv = j;
                ll maxv = j+k;
                while(bp < n && vc[bp].first < minv){ //O(n*n) amortized
                    maxcur = max(maxcur, vc[bp].first + f[vc[bp].second]);
                    bp++;
                }
                if(maxcur > maxv) continue;
                ll qtd = lower_bound(pow.begin(), pow.end(), maxv+1) - lower_bound(pow.begin(), pow.end(), minv);
                ll cur = n - qtd;
                ans = min(ans, cur);
            }
        }
        cout << ans << "\n";
    }
}
