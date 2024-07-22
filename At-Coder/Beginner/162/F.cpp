#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll dp[3][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++){
        if(i == 1){
            dp[0][i] = v[i];
        }else if(i == 2){
            dp[1][i] = v[i];
        }else if(i == 3){
            dp[2][i] = v[i];
            dp[0][i] = dp[0][i-2] + v[i];
        }else{
            dp[0][i] = dp[0][i-2] + v[i];
            dp[1][i] = max(dp[1][i-2] + v[i], dp[0][i-3] + v[i]);
            dp[2][i] = max(dp[2][i-2] + v[i], max(dp[1][i-3] + v[i], dp[0][i-4] + v[i]));
        }
        //cout << dp[0][i] << " " << dp[1][i] << " " << dp[2][i] << "\n";
    }
    if(n % 2){
        ll ans = max(dp[2][n], max(dp[1][n-1], dp[0][n-2]));
        cout << ans << "\n";
    }else{
        ll ans = max(dp[1][n], dp[0][n-1]);
        cout << ans << "\n";
    }
}
