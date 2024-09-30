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
        int n;
        cin >> n;
        vector<vector<ll>> dp(2, vector<ll>(n+1));
        for(int i=1;i<=n;i++){
            dp[0][i] = INF_LL;
            dp[1][i] = -INF_LL;
        }
        for(int i=1;i<=n;i++){
            vector<ll> pv;
            ll x;
            cin >> x;
            pv.push_back(dp[0][i-1] + x);
            pv.push_back(abs(dp[0][i-1] + x));
            pv.push_back(dp[1][i-1] + x);
            pv.push_back(abs(dp[1][i-1] + x));
            for(int j=0;j<4;j++){
                dp[0][i] = min(dp[0][i], pv[j]);
                dp[1][i] = max(dp[1][i], pv[j]);
            }
        }
        cout << dp[1][n] << "\n";
    }
}
