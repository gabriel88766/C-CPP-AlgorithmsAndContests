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
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<vector<int>> adj(n+1);
        for(int i=1;i<n;i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> sub(n+1, 0);
        vector<int> par(n+1, 0);
        function<void(int, int)> dfs = [&](int u, int p){
            sub[u] += 1;
            par[u] = p;
            for(auto v : adj[u]){
                if(v != p){
                    dfs(v, u);
                    sub[u] += sub[v];
                }
            }
        };
        dfs(1, 0);
        ll ans = 0;
        for(int i=1;i<=n;i++){
            int sqt = sqrt(a[i]);
            while(sqt*sqt > a[i]) sqt--;
            while((sqt+1)*(sqt+1) <= a[i]) sqt+=1;
            if(sqt*sqt != a[i]) continue;
            vector<ll> dp(4, 0);
            dp[0] = 1, dp[1] = 1;
            for(auto v : adj[i]){
                int cn;
                if(v == par[i]) cn = n - sub[i];
                else cn = sub[v];
                vector<ll> ndp(4, 0);
                ndp[0] = 1;
                for(int j=3;j>=1;j--){
                    ndp[j] = dp[j] + dp[j-1] * cn;
                }
                dp = ndp;
            }
            ans += dp[3];
        }
        cout << ans << "\n";
    }
}
