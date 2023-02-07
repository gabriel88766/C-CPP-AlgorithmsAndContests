#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[1005][1005];
char grid[1005][1005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int h,w;
    cin >> h >> w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> grid[i][j];
        }
    }
    dp[1][1] = 1;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j] == '#') continue;
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }
    cout << dp[h][w];
}
