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
    // freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, w;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        for(int i=1;i<=m;i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++) adj[i].push_back(i);
        cin >> w;
        vector<vector<int>> adj2(w * n + 1);
        vector<string> vs(n+1);
        for(int i=1;i<=n;i++){
            cin >> vs[i];
        }
        for(int i=0;i<w;i++){
            int nm = (i+1 == w ? 0 : i+1);
            for(int u=1;u<=n;u++){
                if(vs[u][i] != 'o') continue;
                for(auto v : adj[u]){
                    if(vs[v][nm] == 'o'){
                        adj2[i*n + u].push_back(nm*n + v);
                    } 
                }
            }
        }
        //detect cycle
        bool cycle = false;
        vector<int> vis(w*n + 1);
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for(auto v : adj2[u]){
                if(vis[v] == 0){
                    dfs(v);
                }else if(vis[v] == 1){
                    cycle = true;
                }
            }
            vis[u] = 2;
        };
        for(int i=1;i<=w*n;i++){
            if(vis[i] == 0){
                dfs(i);
            }
        }
        if(cycle) cout << "Yes\n";
        else cout << "No\n";
    }
}
