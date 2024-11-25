#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
ll dp[N][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll ans = INF_LL;
    int n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    //option 1: I chose the first v.
    memset(dp, 63, sizeof(dp));
    dp[1][0] = v[1];
    for(int i=2;i<=n;i++){
        //choose
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + v[i];
        dp[i][1] = dp[i-1][0];
    }
    ans = min(dp[n][0], dp[n][1]);
    //option 2: I chose the last instead.
    memset(dp, 63, sizeof(dp));
    dp[1][1] = 0;
    for(int i=2;i<=n;i++){
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + v[i];
        dp[i][1] = dp[i-1][0];
    }
    ans = min(ans, dp[n][0]);
    cout << ans << "\n";
}
