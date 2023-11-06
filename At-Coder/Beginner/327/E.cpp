#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


double dp[5005][5005];
double fat[5005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<double> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]*0.9 + v[i]);
        }
    }
    fat[1] = 1;
    for(int i=2;i<=n;i++) fat[i] = fat[i-1]*0.9 + 1;
    double ans = -1e18;
    for(int i=1;i<=n;i++){
        ans = max(ans, dp[n][i]/fat[i] - 1200.0/sqrt(i));
    }
    cout << fixed << setprecision(15) << ans << "\n";
}
