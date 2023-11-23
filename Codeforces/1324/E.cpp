#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<int>> dp(2, vector<int>(2005, -INF_INT));
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        for(int j=0;j<h;j++) dp[1][j] = -INF_INT;
        for(int j=0;j<h;j++){
            if(dp[0][j] == -INF_INT) continue;
            int dest1 = j + aux - 1;
            int dest2 = j + aux;
            if(dest1 >= h) dest1 -= h;
            if(dest2 >= h) dest2 -= h;

            if(dest1 >= l && dest1 <= r) dp[1][dest1] = max(dp[1][dest1], dp[0][j] + 1);
            else dp[1][dest1] = max(dp[1][dest1], dp[0][j]);
            if(dest2 >= l && dest2 <= r) dp[1][dest2] = max(dp[1][dest2], dp[0][j] + 1);
            else dp[1][dest2] = max(dp[1][dest2], dp[0][j]);
        }
        dp[0] = dp[1];
    }
    int ans = 0;
    for(int j=0;j<h;j++) ans = max(ans, dp[1][j]);
    cout << ans << "\n";
}
