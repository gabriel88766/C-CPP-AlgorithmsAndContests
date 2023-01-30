//Index: 
//1 - Find cycles in undirected/directed
//2 - Topological sort.
//3 - Bipartite check
//(1)Find cycle. O(V+E)
const int N = 2e5+3;
int color[N];
vector<int> adj[N];
int par[N];
int node_begin_cycle;

bool dfs_cycle(int u, int p){
    color[u] = 1;
    par[u] = p;
    for(auto i : adj[u]){
        //if(i == p) continue; //uncomment if undirected.
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
    //reverse(ans.begin(), ans.end()); //
    return ans;
}
//(2)Topological sort O(V+E) directed graph
const int N = 2e5+3;
vector<int> topo;
bool visited[N];
vector<int> adj[N];

void dfs_topo(int u){
    visited[u] = true;
    for(auto i : adj[u]){
        if(!visited[i]){
            dfs_topo(i);
        }
    }
    topo.push_back(u);
}
void topo_sort(int n){ 
    for(int i=1;i<=n;i++) visited[i] = false;
    for(int i=1;i<=n;i++) if(!visited[i]) dfs_topo(i);
    reverse(topo.begin(), topo.end());   
}
//(3) Bipartite check O(V+E)
const int INF_INT = 0x3f3f3f3f;
const int N = 2e5+3;
vector<int> adj[N];
int c[N]; // 0 OR 1

bool bfs_bipartite(int src){
    queue<int> q;
    q.push(src); 
    c[src] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(c[v] == c[u]) return false;
            if(c[v] == INF_INT){
                c[v] = c[u] ^ 1;
                q.push(v);
            }
        }
    }
    return true;
}
bool isbiparitite(int n){
    memset(c, 63, sizeof(c));
    for(int i=1;i<=n;i++) if(c[i] == INF_INT && !bfs_bipartite(i)) return false;
    return true;
}