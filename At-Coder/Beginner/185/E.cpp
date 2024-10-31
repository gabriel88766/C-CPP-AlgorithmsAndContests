#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[1005][1005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<int> b(m+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> b[i];
    memset(dp, 63, sizeof(dp));
    dp[0][0] = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i == 0 && j == 0) continue;
            if(i == 0){
                dp[i][j] = dp[i][j-1] + 1;
            }else if(j == 0){
                dp[i][j] = dp[i-1][j] + 1;
            }else{
                if(a[i] == b[j]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            }
        }
    }
    cout << dp[n][m] << "\n";
}
