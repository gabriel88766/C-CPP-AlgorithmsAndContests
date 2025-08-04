#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[1 << 20];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m, b;
    cin >> n >> m >> b;
    vector<tuple<ll, ll, ll>> vx;
    for(int i=1;i<=n;i++){
        ll x, k, mx;
        cin >> x >> k >> mx;
        int msk = 0;
        for(int j=0;j<mx;j++){
            int y;
            cin >> y;
            msk |= (1 << (y-1));
        }
        vx.push_back({k, x, msk});
    }
    sort(vx.begin(), vx.end());
    memset(dp, 63, sizeof(dp));
    ll ans = INF_LL;
    dp[0] = 0;
    for(auto [k, x, msk] : vx){
        for(int j=0;j<(1 << m);j++){
            dp[j | msk] = min(dp[j | msk], dp[j] + x);
        }
        ans = min(ans, dp[(1 << m) - 1] + k * b);
    }
    if(ans != INF_LL) cout << ans << "\n";
    else cout << "-1\n";
}
