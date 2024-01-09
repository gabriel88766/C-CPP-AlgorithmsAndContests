#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int vis[N];
vector<pair<int,int>> und;
vector<int> adj[N];
vector<int> topo;
int n;

bool dfs_cycle(int u){
    vis[u] = 1;
    bool ans = false;
    for(auto v : adj[u]){
        if(vis[v] == 1) return true;
        else if(vis[v] == 0){
            ans |= dfs_cycle(v);
        }
    }
    vis[u] = 2;
    return ans;
}

void dfs(int u){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v]) dfs(v);
    }
    topo.push_back(u);
}

void toposort(){
    topo.clear();
    for(int i=1;i<=n;i++) vis[i] = 0;
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    reverse(topo.begin(), topo.end());
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            vis[i] = 0;
            adj[i].clear();
        }
        und.clear();
        for(int i=0;i<m;i++){
            int c, u, v;
            cin >> c >> u >> v;
            if(c == 0){
                und.push_back({u, v});
            }else{
                adj[u].push_back(v);
            }
        }
        bool ok = true;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(dfs_cycle(i)) ok = false;
            }
        }
        if(ok){
            cout << "YES\n";
            toposort();
            vector<int> invt(n+1);
            for(int i=0;i<n;i++) invt[topo[i]] = i;
            for(auto [u, v] : und){
                if(invt[u] < invt[v]) adj[u].push_back(v);
                else adj[v].push_back(u);
            }
            for(int i=1;i<=n;i++){
                for(auto v : adj[i]){
                    cout << i << " " << v << "\n";
                }
            }

        }else cout << "NO\n";
    }
}
