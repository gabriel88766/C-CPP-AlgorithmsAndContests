#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char gr[105][105];
int dp[105][105];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    int ans = 0;
    cin >> n >> m;
    memset(dp, 255, sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> gr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i == 1 && j == 1) dp[i][j] = 1;
            else if(gr[i][j] != '#'){
                if(dp[i][j-1] > 0) dp[i][j] = max(dp[i][j], dp[i][j-1] + 1);
                if(dp[i-1][j] > 0) dp[i][j] = max(dp[i][j], dp[i-1][j] + 1);
            }
            if(dp[i][j] > 0) ans = max(dp[i][j], ans);
        }
    }
    cout << ans << "\n";
}
