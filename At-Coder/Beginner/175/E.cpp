#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
ll dp[N][N][4];
ll val[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int r,c, k;
    cin >> r >> c >> k;
    for(int i=1;i<=k;i++){
        int r, c, v;
        cin >> r >> c >> v;
        val[r][c] = v;
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            for(int x = 0; x<=3;x++) dp[i][j][0] = max(dp[i-1][j][x], dp[i][j][0]);
            for(int x = 0; x<=3;x++) dp[i][j][1] = max(dp[i-1][j][x] + val[i][j], dp[i][j][1]);
            for(int x=0;x<=3;x++){
                dp[i][j][x] = max(dp[i][j][x], dp[i][j-1][x]);
                if(x != 0) dp[i][j][x] = max(dp[i][j-1][x-1] + val[i][j], dp[i][j][x]);
            }
            // cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << " " << dp[i][j][2] << " " << dp[i][j][3] << "\n";
        }
    }
    cout << max({dp[r][c][0], dp[r][c][1], dp[r][c][2], dp[r][c][3]}) << "\n";
}
