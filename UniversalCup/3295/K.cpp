#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 505, INF = 1e9;
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

int hv[N];
vector<int> adj[N];
void dfsh(int u, int p){
    hv[u] = hv[p] + 1;
    for(auto v : adj[u]){
        dfsh(v, u);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    if(s == "prepare"){
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        hv[0] = -1;
        dfsh(1, 0);
        src = 0, snk = n+1;
        for(int i=1;i<=n;i++){
            if(hv[i] % 2){
                add_edge(i, snk, 1);
                for(auto v : adj[i]){
                    add_edge(v, i, 1);
                }
            }else{
                add_edge(src, i, 1);
                for(auto v : adj[i]){
                    add_edge(i, v, 1);
                }
            }
        }
        int cc = dinic();
        string ans(n-1, '0');
        for(int i=1;i<=n;i++){
            if(hv[i] % 2 == 0){
                for(auto k : g[i]){
                    if(edgs[k].f == 1){
                        int cv = edgs[k].v;
                        int cu = i;
                        //TODO : cu, cv faz parte do matching 
                    }
                }
            }
        }
        //TODO : fazer a ans
        cout << ans << "\n";
        cout.flush();
    }else{
        int n;
        cin >> n;
        string s;
        cin >> s;
        for(int i=1;i<n;i++){
            int u, v;
            cin >> u >> v;
            if(u == 1 && s[v] == '0') cout << "take\n";
            else if(s[v-2] == s[u-2]) cout << "take\n";
            else cout << "ignore\n";
            cout.flush();
        }
    }
}
