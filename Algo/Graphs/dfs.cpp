//O(V+E)
const int N = 2e5+3;
vector<int> adj[N];
bool visited[N];

void dfs(int u){
    visited[u] = true;
    for(auto i : adj[u]){
        if(!visited[i]){
            dfs(i);
        }
    }
}