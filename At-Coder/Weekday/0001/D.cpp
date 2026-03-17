#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 205;
ll dp[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ll a, b;
        cin >> a >> b;
        for(int j=max(i-k, 0); j < i; j++){
            for(int u = m; u >= b; u--){
                dp[i][u] = max(dp[i][u], dp[j][u - b] + a);
                ans = max(ans, dp[i][u]);
            }
        }
    }
    cout << ans << "\n";
}
