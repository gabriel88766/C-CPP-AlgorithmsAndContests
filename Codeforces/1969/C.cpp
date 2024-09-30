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
        int n, k;
        cin >> n >> k;
        vector<ll> v(n+2);
        vector<vector<ll>> dp(n+1, vector<ll>(k+1, INF_LL));
        dp[0][0] = 0;
        v[0] = v[n+1] = INF_LL;
        for(int i=1;i<=n;i++){
            cin >> v[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(k, i);j++){
                ll mv = min(v[i+1], v[i]);
                for(int ch=1;ch<=min(j, i);ch++){
                    mv = min(mv, v[i-ch]);
                    dp[i][j] = min(dp[i][j], dp[i-ch][j-ch] + ch*mv);
                }
                dp[i][j] = min(dp[i][j], dp[i-1][j] + v[i]);
            }
        }
        ll ans = INF_LL;
        for(int j=0;j<=k;j++) ans = min(ans, dp[n][j]);
        cout << ans << "\n";
    }
}
