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
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<ll> v(n+1), ps(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=1;i<=n;i++){
            ps[i] = ps[i-1] + v[i];
        }
        ll mv = *max_element(ps.begin(), ps.end());
        vector<pair<ll, ll>> vp = {{0, 0}};
        for(int i=1;i<=n;i++){
            if(ps[i] > vp.back().first){
                vp.push_back({ps[i], i});
            }
        }
        for(int i=0;i<m;i++){
            ll x;
            cin >> x;
            if(ps[n] <= 0 && mv < x) cout << "-1 ";
            else if(mv >= x){
                auto it = lower_bound(vp.begin(), vp.end(), make_pair(x, 0LL));
                cout << it->second - 1 << " ";
            }else{
                assert(ps[n] > 0);
                ll tt = (x-mv-1)/ps[n]+1;
                ll ans = tt*n;
                ll xt = ps[n] * tt;
                assert(xt <= x);
                auto it = lower_bound(vp.begin(), vp.end(), make_pair<ll, ll>(x - xt, 0));
                assert(it != vp.end());
                ans += it->second - 1;
                cout << ans << " ";
            }
        }

        cout << "\n";
    }
}
