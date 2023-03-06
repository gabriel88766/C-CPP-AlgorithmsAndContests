#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll v[101][101];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        set<ll> posv;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> v[i][j];
                posv.insert(v[i][j] - i - j + 2);
            }
        }
        ll ans = INF_LL;
        for(auto x : posv){
            if(x > v[1][1]) break;
            vector<vector<ll>> dp(n+1, vector<ll> (m+1, INF_LL));
            dp[1][1] = v[1][1] - x;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(i == 1 && j == 1) continue;
                    if(v[i][j] < (x+i+j-2)) continue;
                    if(i != 1) dp[i][j] = min(dp[i][j], dp[i-1][j] + v[i][j]-(x+i+j-2));
                    if(j != 1) dp[i][j] = min(dp[i][j], dp[i][j-1] + v[i][j]-(x+i+j-2));
                }
            }
            ans = min(ans, dp[n][m]);
        }
        cout << ans << "\n";
    }
}
