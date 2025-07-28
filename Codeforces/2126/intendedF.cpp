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
        int n, q;
        cin >> n >> q;
        vector<int> cl(n+1);
        vector<vector<pair<int, int>>> adj(n+1);
        vector<int> par(n+1);
        for(int i=1;i<=n;i++) cin >> cl[i];
        for(int i=1;i<n;i++){
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        for(int i=1;i<=n;i++) sort(adj[i].begin(), adj[i].end());
        vector<map<ll, ll>> mp(n+1);
        ll ans = 0;
        function<void(int, int)> dfs = [&](int u, int p){
            par[u] = p;
            for(auto [v, w] : adj[u]){
                if(v != p){
                    ans += w;
                    mp[u][cl[v]] += w;
                    dfs(v, u);
                }
            }
            if(mp[u].count(cl[u])) ans -= mp[u][cl[u]];
        };
        dfs(1, 0);
        for(int i=1;i<=q;i++){
            int u, x;
            cin >> u >> x;
            if(mp[u].count(cl[u])){
                ans += mp[u][cl[u]];
            }
            if(mp[u].count(x)){
                ans -= mp[u][x];
            }
            if(par[u] != 0){
                auto [xxx, w] = *lower_bound(adj[par[u]].begin(), adj[par[u]].end(), make_pair(u, 0));
                assert(xxx == u);
                if(cl[par[u]] == cl[u]) ans += w;
                if(cl[par[u]] == x) ans -= w;
                mp[par[u]][cl[u]] -= w;
                mp[par[u]][x] += w;
            }
            cout << ans << "\n";
            cl[u] = x;
        }
    }
}
