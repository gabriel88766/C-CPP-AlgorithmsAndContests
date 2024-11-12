#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 305;
int dp[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, x, y;
    cin >> n >> x >> y;
    memset(dp, 63, sizeof(dp));
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        for(int j=x;j>=0;j--){
            for(int k=y;k>=0;k--){
                dp[j][k] = min(dp[j][k], dp[max(j-a, 0)][max(k-b, 0)] + 1);
                dp[j][k] = min(dp[j][k], dp[j+1][k]);
                dp[j][k] = min(dp[j][k], dp[j][k+1]);
            }
        }
    }
    if(dp[x][y] != INF_INT) cout << dp[x][y] << "\n";
    else cout << "-1\n";
}
