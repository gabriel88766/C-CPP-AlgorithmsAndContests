#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> v(n+1);
    vector<ll> c(k+1), h(k+1);
    vector<vector<ll>> dp(n+1, vector<ll> (n+1, INF_LL));
    

    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=k;i++) cin >> c[i];
    for(int i=1;i<=k;i++) cin >> h[i];

    dp[0][0] = 0;
    dp[1][0] = dp[0][1] = c[v[1]];
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            if(j != (i-1)){
                dp[i][j] = dp[i-1][j] + (v[i-1] == v[i] ? h[v[i]] : c[v[i]]);
                dp[j][i] = dp[j][i-1] + (v[i-1] == v[i] ? h[v[i]] : c[v[i]]);
            }else{
                for(int k=0;k<(i-1);k++){
                    dp[i][j] = min(dp[i][j], dp[k][j] + (v[k] == v[i] ? h[v[i]] : c[v[i]]));
                    dp[j][i] = min(dp[j][i], dp[j][k] + (v[k] == v[i] ? h[v[i]] : c[v[i]]));
                }
            }
        }
    }
    ll ans = INF_LL;
    for(int i=0;i<n;i++){
        ans = min(ans, dp[n][i]);
        ans = min(ans, dp[i][n]);
    }
    cout << ans << "\n";
    
    
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
