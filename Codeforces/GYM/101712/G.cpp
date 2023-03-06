#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
const ll INF = 1e18;
struct edge {ll v, c, f;};

int n, src, snk, h[N], ptr[N];
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

ll dfs (int u, ll flow) {
    if (!flow or u == snk) return flow;
    for (int &i = ptr[u]; i < g[u].size(); ++i) {
        edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
        int v = dir.v;
        if (h[v] != h[u] + 1)  continue;
        ll inc = min(flow, dir.c - dir.f);
        inc = dfs(v, inc);
        if (inc) {
            dir.f += inc, rev.f -= inc;
            return inc;
        }
    }
    return 0;
}

ll dinic() {
    ll flow = 0;
    while (bfs()) {
        memset(ptr, 0, sizeof ptr);
        while (ll inc = dfs(src, INF)) flow += inc;
    }
    return flow;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    src = 1;
    int n, m;
    cin >> n >> m;
    snk = n;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a,b,c);
    }
    ll fl = dinic();
    cout << fl << "\n";
    for(int i=0;i<edgs.size();i++){
        if(edgs[i].c > 0){
            cout << edgs[i].f << "\n";
        }
    }
    
}
