#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 205;
vector<int> adj[N];
int dfs_low[N], dfs_num[N], cmpnum[N], cntT = 0, cntCmp=0;
int val[N];
int rv[N];
vector<int> cmp[N], curcmp;
char visc[N];

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
            cmpnum[v] = cntCmp;
            if(v == u) break;
        }
        for(auto x : cmp[cntCmp]) rv[cntCmp] += val[x];
    }
}

vector<int> adjc[N]; //condensation graph
void make_cgscc(int n){
    for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);
    vector<bool> used(cntCmp+1, false);
    for(int i=1;i<=cntCmp;i++){
        for(auto &u : cmp[i]){
            for(auto &v : adj[u]){
                if(cmpnum[v] != i && (used[cmpnum[v]] == false)){
                    used[cmpnum[v]] = true;
                    adjc[i].push_back(cmpnum[v]);
                }
            }
        }
        for(auto &x : adjc[i]) used[x] = false;
    }
}



const int INF = 1e9;
struct edge {int v, c, f;};

int src, snk, h[N], ptr[N];
vector<edge> edgs;
vector<int> g[N];

void add_edge (int u, int v, int c) {
    int k = edgs.size();
    edgs.push_back({v, c, 0});
    edgs.push_back({u, 0, 0});
    g[u].push_back(k);
    g[v].push_back(k+1);
}

bool bfs() {
    memset(h, 0, sizeof h);
    //for(int i=src;i<=snk;i++) h[i] = 0;
    queue<int> q;
    h[src] = 1;
    q.push(src);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i : g[u]) {
            int v = edgs[i].v;
            if (!h[v] && edgs[i].f < edgs[i].c)
                q.push(v), h[v] = h[u] + 1;
        }
    }
    return h[snk];
}

int dfs (int u, int flow) {
    if (!flow or u == snk) return flow;
    for (int &i = ptr[u]; i < g[u].size(); ++i) {
        edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
        int v = dir.v;
        if (h[v] != h[u] + 1)  continue;
        int inc = min(flow, dir.c - dir.f);
        inc = dfs(v, inc);
        if (inc) {
            dir.f += inc, rev.f -= inc;
            return inc;
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        memset(ptr, 0, sizeof ptr);
        //for(int i=src;i<=snk;i++) ptr[i] = 0;
        while (int inc = dfs(src, INF)) flow += inc;
    }
    return flow;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> val[i];
    }
    ll ans = 0;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        //u
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);
    make_cgscc(n);
    src = 0, snk = cntCmp + 1;
    for(int i=1;i<=cntCmp;i++){
        if(rv[i] >= 0){
            ans += rv[i];
            add_edge(src, i, rv[i]);
        }else{
            add_edge(i, snk, -rv[i]);
        }
        for(auto v : adjc[i]){
            add_edge(i, v, INF);
        }
    }
    ans -= dinic();
    cout << ans << "\n";
    
}
