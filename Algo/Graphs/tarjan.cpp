//O(V+E)
const int N = 2e5+3;
vector<int> adj[N];
int dfs_low[N], dfs_num[N], cntT = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
char visc[N];

// for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);
void tarjan(int u){ //SCC, cmp is in inverse topological order 
    dfs_low[u] = dfs_num[u] = ++cntT;
    visc[u] = 1;
    curcmp.emplace_back(u);
    for(auto v : adj[u]){
        if(!dfs_num[v]) tarjan(v);
        if(visc[v] == 1) dfs_low[u] = min(dfs_low[v], dfs_low[u]);
    }
    if(dfs_low[u] == dfs_num[u]){
        ++cntCmp;
        while(true){
            int v = curcmp.back(); curcmp.pop_back(); visc[v] = 2;
            cmp[cntCmp].emplace_back(v);
            if(v == u) break;
        }
    }
}