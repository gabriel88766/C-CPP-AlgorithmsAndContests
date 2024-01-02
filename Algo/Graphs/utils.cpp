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
bool vis[N];
vector<int> adj[N];

void dfs_topo(int u){
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs_topo(i);
        }
    }
    topo.push_back(u);
}
void topo_sort(int n){ 
    for(int i=1;i<=n;i++) vis[i] = false;
    for(int i=1;i<=n;i++) if(!vis[i]) dfs_topo(i);
    reverse(topo.begin(), topo.end());   
}
//Kahn
int indg[N]; //indg[b] = qt[a] | a -> b
queue<int> q;
vector<int> topo;
while(!q.empty()){ //priority queue for first lexicographical order,
    int u = q.front(); //if(q.size() >= 2) then not unique.
    q.pop();
    for(auto x : adj[u]){
        indg[x]--;
        if(indg[x] == 0) q.push(x);
    }
    topo.push_back(u);
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
//(4) Find bridges in O(V+E) // (5) Find Articulation Points O(V+E)
const int N = 2e5+3;
vector<int> adj[N];
int in[N], low[N], cnt = 0;
vector<pair<int,int>> bdgs;
vector<int> artp;

void dfs_bridge(int u, int p = -1){
    low[u] = in[u] = ++cnt;
    for(auto v: adj[u]){
        if(v == p) continue;
        if(!in[v]){
            dfs_bridge(v, u);
            if(low[v] == in[v]) bdgs.push_back({u, v});
        }
        low[u] = min(low[u], low[v]);
    }
}


void dfs_artp(int u, int p = -1){
    low[u] = in[u] = ++cnt;
    int ch = 0;
    for(auto v: adj[u]){
        if(v == p) continue;
        if(!in[v]){
            dfs_artp(v, u);
            if(low[v] >= in[u] && p != -1){
                artp.push_back(u);
            }
            ch++;
            low[u] = min(low[u], low[v]);
        }else low[u] = min(low[u], in[v]);
    }
    if(p == -1 && ch > 1){
        //artic point. if removed, ch-1 more components
        artp.push_back(u);
    }
}