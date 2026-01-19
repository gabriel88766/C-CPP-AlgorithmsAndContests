#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[5], ndp[5];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[0] = 0;
    dp[1] = dp[2] = dp[3] = dp[4] = -INF_LL;
    int ct = 0;
    int n;
    cin >> n;
    for(int j=1;j<=n;j++){
        int t, x, a;
        cin >> t >> x >> a;
        for(int k=ct+1;k<=t;k++){
            ndp[0] = ndp[1] = ndp[2] = ndp[3] = ndp[4] = -INF_LL;
            ndp[0] = max(dp[0], dp[1]);
            ndp[1] = max({dp[0], dp[1], dp[2]});
            ndp[2] = max({dp[1], dp[2], dp[3]});
            ndp[3] = max({dp[2], dp[3], dp[4]});
            ndp[4] = max({dp[3], dp[4]});
            for(int u=0;u<=4;u++) dp[u] = ndp[u];
        }
        ct = t;
        dp[x] += a;
    }
    cout << max({dp[0], dp[1], dp[2], dp[3], dp[4]}) << "\n";
}
