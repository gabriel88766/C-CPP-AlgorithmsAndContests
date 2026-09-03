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
    //check if the graph is bipartite
    //if not, find the cycle somehow...
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //bipartite check.
        vector<int> cl(n+1, -1);
        vector<int> par(n+1, -1);
        int bg = -1;
        function<void(int)> dfs = [&](int u){
            for(auto v : adj[u]){
                if(bg != -1) break; //early break all dfs.
                if(cl[v] == -1){
                    cl[v] = cl[u] ^ 1;
                    par[v] = u;
                    dfs(v);
                }else if(cl[v] == cl[u]){
                    bg = v;
                    par[v] = u;
                }
            }
        };
        
        for(int i = 1; i <= n; i++){
            if(cl[i] == -1){
                cl[i] = 0;
                dfs(i);
            }
            if(bg != -1) break;
        }
        if(bg == -1) cout << -1 << "\n";
        else{
            vector<int> ans = {bg};
            int cur = par[bg];
            while(cur != bg){
                ans.push_back(cur);
                cur = par[cur];
            }
            cout << ans.size() << "\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }
    }
}
