#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[200];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, s, m, l;
    cin >> n >> s >> m >> l; //6, 8, 12
    dp[0] = 0;
    for(int i=1;i<=150;i++) dp[i] = INF_INT;
    for(int i=0;i<=150;i++){
        dp[i+6] = min(dp[i+6], dp[i] + s);
        dp[i+8] = min(dp[i+8], dp[i] + m);
        dp[i+12] = min(dp[i+12], dp[i] + l);
    }
    int ans = INF_INT;
    for(int i=n;i<=150;i++){
        ans = min(ans, dp[i]);
    }
    cout << ans << "\n";
}
 