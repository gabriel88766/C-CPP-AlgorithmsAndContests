#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[2][5005];
ll st[5005];
ll wc[5005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=0;i<=5000;i++) dp[0][i] = dp[1][i] = -1;
    dp[0][0] = 0;
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> wc[i];
    for(int i=1;i<=m;i++){
        int x, c;
        cin >> c >> x;
        st[c] = x;
    }
    for(int i=1;i<=n;i++){
        int b = i & 1;
        for(int j=0;j<=i;j++) dp[b][j] = -1;
        for(int j=0;j<i;j++){
            assert(dp[b^1][j] != -1);
            dp[b][0] = max(dp[b][0], dp[b^1][j]);
            dp[b][j+1] = dp[b^1][j] + st[j+1] + wc[i];
        }
    }
    ll ans = 0;
    for(int j=0;j<=n;j++) ans = max(ans, dp[n&1][j]);
    cout << ans << "\n";
}
