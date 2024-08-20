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
        int n, d;
        cin >> n >> d;
        vector<int> v(n);
        bool h1 = false;
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(v[i] == 1) h1 = true;
        }
        if(!h1) cout << "0\n";
        else{
            //h1 = true
            vector<int> adj(n, -1);
            vector<int> sz(n, 0), vis(n, 0);
            for(int i=0;i<n;i++){
                if(v[i] == 1 && v[(n-d+i)%n] == 1){
                    adj[i] = (n - d + i) % n;
                }
            }
            function<void(int)> dfs = [&](int u){
                vis[u] = 1;
                if(adj[u] == -1) sz[u] = 1;
                else{
                    if(vis[adj[u]] == 2) sz[u] = min(sz[adj[u]] + 1, INF_INT);
                    else if(vis[adj[u]] == 1) sz[u] = INF_INT;
                    else{
                        dfs(adj[u]);
                        sz[u] = min(sz[adj[u]] + 1, INF_INT);
                    }
                }
                vis[u] = 2;
            };
            int ans = 0;
            for(int i=0;i<n;i++){
                if(v[i] == 1 && !vis[i]) dfs(i);
                ans = max(ans, sz[i]);
            }
            if(ans == INF_INT) cout << "-1\n";
            else cout << ans << "\n";

        }
    }
}
