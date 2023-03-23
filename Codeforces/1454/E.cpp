#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int par[N], vis[N], color[N];
ll ts[N];
int node_begin_cycle;

bool dfs_cycle(int u, int p){
    color[u] = 1;
    par[u] = p;
    for(auto i : adj[u]){
        if(i == p) continue; //uncomment if undirected.
        if(color[i] == 0 && dfs_cycle(i, u)) return true;
        else if(color[i] == 1){
            node_begin_cycle = i;
            par[i] = u;
            return true; 
        }
    }
    color[u] = 2;
    return false;
}
vector<int> find_cycle(int n){ //if returned vector is empty, then no cycle
    vector<int> ans;
    node_begin_cycle = -1;
    for(int i=1;i<=n;i++) color[i] = 0;
    for(int i=1;i<=n;i++) if(!color[i] && dfs_cycle(i, -1)) break;
    if(node_begin_cycle == -1) return ans;
    int s = node_begin_cycle, cur = node_begin_cycle;
    do{
        ans.push_back(cur);
        cur = par[cur];
    }while(cur != s);
    ans.push_back(cur);
    return ans;
}

set<int> curcyc;

void dfs(int u){
    vis[u] = true;
    ts[u]++;
    for(auto v : adj[u]){
        if(!curcyc.count(v) && !vis[v]){
            dfs(v);
            ts[u] += ts[v];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
            int a, b;
            vis[i] = false;
            ts[i] = 0;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        auto cyc = find_cycle(n);
        for(auto x : cyc) {
            curcyc.insert(x);
        }
        ll ans = 0;
        for(auto x : curcyc){
            dfs(x);
            ans += ts[x]*((ts[x]-1) + 2*(n-ts[x]));
        }
        cout << ans/2 << "\n";

        for(int i=1;i<=n;i++) adj[i].clear();
        curcyc.clear();
    }

    
}