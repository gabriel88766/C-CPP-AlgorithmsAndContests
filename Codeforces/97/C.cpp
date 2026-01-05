#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

double pd[105];
double dp[205];
double ndp[205];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<=n;i++) cin >> pd[i];
    const int IT = 5000;
    const int MAXD = 200;
    dp[0] = 0;
    double ans = -1e18;
    for(int i=1;i<=MAXD;i++) dp[i] = -1e18;
    for(int i=1;i<=IT;i++){
        for(int i=0;i<=MAXD;i++) ndp[i] = -1e18;
        for(int j=0;j<=MAXD;j++){
            for(int k=0;k<=n;k++){
                if(j + n - 2 * k >= 0 && j + n - 2 * k <= MAXD) ndp[j + n - 2*k] = max(ndp[j + n - 2*k], dp[j] + pd[k]);
            }
        }
        for(int i=0;i<=MAXD;i++){
            dp[i] = ndp[i];
        } 
        ans = max(ans, dp[0]/i);
    }
    cout << fixed << setprecision(10) << ans << "\n";
}
