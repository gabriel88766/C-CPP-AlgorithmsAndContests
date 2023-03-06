#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1, INF = 1e9;
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
        while (int inc = dfs(src, INF)) flow += inc;
    }
    return flow;
}

bool pos[41][41];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    src = 3201, snk = 3202;
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) pos[i][j] = true;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        pos[a][b] = false;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(pos[i+1][j+1] && pos[i+2][j+1]) add_edge(i*n + j + 1, (i+1)*n + j + 1 + 1600, 1);
            if(pos[i+1][j+1] && pos[i+1][j+2]) add_edge(i*n + j + 1, i*n + j + 2 + 1600, 1);
        }
    }
    for(int i=1;i<=1600;i++) add_edge(i+1600, snk, 1), add_edge(src, i, 1);
    int fl = dinic();
    cout << fl << " " << m << " " << n*n << "\n";
    if((fl+4 + m) != (n*n)) cout << "No\n";
    else{
        vector<pair<int,int>> hor, ver;
        for(int i=1;i<=n*n;i++){
            for(auto x : g[i]){
                if(edgs[x].f == 1){
                    int indi = (i-1)/n + 1, indj = ((i-1) % n) + 1;
                    if(edgs[x].v != (i+n+1600)) hor.push_back({indi, indj});
                    else ver.push_back({indi, indj});
                }
            }
        }
        cout << hor.size() << "\n";
        for(int i=0;i<hor.size();i++) cout << hor[i].first << " " << hor[i].second << "\n";
        cout << ver.size() << "\n";
        for(int i=0;i<ver.size();i++) cout << ver[i].first << " " << ver[i].second << "\n";
    }
    
}
 