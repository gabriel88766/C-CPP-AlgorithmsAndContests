#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 201;
int dp[N][N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dp, 63, sizeof(dp));
    dp[1][1] = 0;
    int ans = 0;
    for(int i=2;i<=200;i++){
        for(int j=1;j<i;j++){
            int mx = max(j, i-j);
            int mn = min(j, i-j);
            dp[i][mx] = min(dp[i][mx], dp[mx][mn] + 1);
            dp[i][mn] = min(dp[i][mn], dp[mx][mn] + 1);
        }
        for(int j=1;j<=i-2;j++) dp[i][j] = min(dp[i][j], dp[i-2][j] + 1), dp[i][i-2] = min(dp[i][i-2], dp[i-2][j] + 1);
        for(int j=1;j<=i-1;j++) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1), dp[i][i-1] = min(dp[i][i-1], dp[i-1][j] + 1);
        for(int j=1;j<i;j++){
            dp[i][i] = min(dp[i][i], dp[i][j]);
            dp[i][1] = min(dp[i][1], dp[i][j]);
        }
        ans += dp[i][i];
    }
    cout << ans << "\n";

}
