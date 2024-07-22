#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        vector<vector<ll>> dp(25, vector<ll>(n+1, INF_LL));
        vector<ll> v(n+1);
        function<void(int, int)> dfs = [&](int u, int p){
            int x = adj[u].size();
            vector<pair<int,int>> bst(x);
            vector<vector<int>> bs(25);
            ll S = 0;
            for(int i=0;i<adj[u].size();i++){
                auto x = adj[u][i];
                if(x != p){
                    dfs(x, u);
                    ll b = INF_LL;
                    ll bi, sbi;
                    for(int j=1;j<=24;j++){
                        if(dp[j][x] < b){
                            bi = j;
                            b = dp[j][x];
                        }
                    }
                    S += b;
                    b = INF_LL;
                    for(int j=1;j<=24;j++){
                        if(j == bi) continue;
                        if(dp[j][x] < b){
                            sbi = j;
                            b = dp[j][x];
                        }
                    }
                    bst[i] = {bi, sbi};
                    bs[bi].push_back(i);
                }
            }
            for(int i=1;i<=24;i++){
                ll CS = S;
                for(auto x : bs[i]){
                    auto v = adj[u][x];
                    CS += dp[bst[x].second][v] - dp[bst[x].first][v] ;
                }
                dp[i][u] = CS + v[u]*i;
            }
        };
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ll ans = INF_LL;
        dfs(1, 0);
        for(int i=1;i<=24;i++) ans = min(ans, dp[i][1]);
        cout << ans << "\n";
    }
}
