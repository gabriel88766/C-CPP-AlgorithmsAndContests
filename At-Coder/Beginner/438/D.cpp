#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
ll a[N], b[N], c[N];
ll dp[N][3];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++) cin >> c[i];
    dp[1][0] = a[1];
    dp[1][1] = -INF_LL;
    dp[1][2] = -INF_LL;

    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][0] + a[i];
        dp[i][1] = max(dp[i-1][1] + b[i], dp[i-1][0] + b[i]);
        dp[i][2] = max(dp[i-1][2] + c[i], dp[i-1][1] + c[i]);
    }
    cout << dp[n][2] << "\n";
}
