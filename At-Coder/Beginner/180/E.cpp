#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[1 << 18][18];
ll x[18], y[18], z[18];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i] >> z[i];
    }
    memset(dp, 63, sizeof(dp));
    dp[1][0] = 0;
    for(int i=1;i<(1 << n)-1; i++){
        for(int k=0;k<n;k++){
            if(i & (1 << k)){
                for(int nb=0;nb<n;nb++){
                    if(i & (1 << nb)) continue;
                    int ns = i | (1 << nb);
                    dp[ns][nb] = min(dp[ns][nb], dp[i][k] + abs(x[nb] - x[k]) + abs(y[nb] - y[k]) + max(0LL, z[nb] - z[k]));
                }
            }
        }
    }
    ll ans = INF_LL;
    for(int k=1;k<n;k++){
        ans = min(ans, dp[(1 << n) - 1][k] + abs(x[0]-x[k]) + abs(y[0] - y[k]) + max(0LL, z[0] - z[k]));
    }
    cout << ans << "\n";
}
