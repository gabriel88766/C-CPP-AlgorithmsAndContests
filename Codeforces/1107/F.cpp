#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[505][505];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<tuple<ll, ll, ll>> vt;
    for(int i=1;i<=n;i++){
        ll a, b, k;
        cin >> a >> b >> k;
        vt.push_back({b, a, k});
    }
    sort(vt.begin(), vt.end(), greater<tuple<ll,ll,ll>>());
    ll ans = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = -INF_LL;
        }
    }
    dp[0][0] = 0;
    for(auto [b, a, k] : vt){
        for(int i=n;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(dp[i][j] == -INF_LL) continue;
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a - i*b);
                dp[i][j+1] = max(dp[i][j+1], dp[i][j] + a - k*b);
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}
