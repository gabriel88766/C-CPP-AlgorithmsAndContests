//O(V+E)
const int N = 2e5+3;
vector<int> adj[N];
bool vis[N];

void dfs(int u){
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs(i);
        }
    }
}