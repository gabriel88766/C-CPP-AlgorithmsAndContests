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
        ll x;
        cin >> n >> k >> x;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(k+1, vector<ll>(3, -INF_LL)));
        dp[0][0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(j){
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][0]);
                    dp[i][j][1] = max(dp[i-1][j][1] + v[i] - x, dp[i-1][j][0] + v[i] - x); 
                    dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][1] + v[i] + x);
                    dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][0] + v[i] + x); 
                    dp[i][j][2] = max(dp[i-1][j][2], dp[i-1][j-1][2]);
                    dp[i][j][2] = max(dp[i][j][2], dp[i-1][j][1]);
                    dp[i][j][2] = max(dp[i][j][2], dp[i-1][j-1][1]);
                }else{
                    dp[i][j][0] = dp[i-1][j][0];
                    dp[i][j][1] = max(dp[i-1][j][1] + v[i] - x, dp[i-1][j][0] + v[i] - x); 
                    dp[i][j][2] = max(dp[i-1][j][2], dp[i-1][j][1]);
                }
            }
        }
        cout << max(dp[n][k][2], max(dp[n][k][1], 0LL)) << "\n";
    }
}   
