#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[2005][2], v[2005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, z, w;
    cin >> n >> z >> w;
    for(int i=1;i<=n;i++) cin >> v[i];
    if(n == 1){
        cout << abs(v[1] - w) << "\n";
        return 0;
    }
    dp[n][1] = dp[n][0] = abs(v[n] - v[n-1]);
    for(int i=n-1;i>=1;i--){
        // 0 maximize, 1 minimize
        dp[i][0] = 0;
        dp[i][1] = INF_INT;
        for(int j=i+1;j<=n;j++) dp[i][0] = max(dp[i][0], dp[j][1]);
        for(int j=i+1;j<=n;j++) dp[i][1] = min(dp[i][1], dp[j][0]);
        dp[i][0] = max(dp[i][0], abs(v[n] - (i == 1 ? w : v[i-1])));
        dp[i][1] = min(dp[i][1], abs(v[n] - (i == 1 ? z : v[i-1])));
    }
    cout << dp[1][0] << "\n";
} 
