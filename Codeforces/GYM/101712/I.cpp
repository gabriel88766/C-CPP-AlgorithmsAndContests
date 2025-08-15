#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
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
    // memset(h, 0, sizeof h);
    for(int i=0;i<=snk;i++) h[i] = 0;
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
        // memset(ptr, 0, sizeof ptr);
        for(int i=0;i<=snk;i++) ptr[i] = 0;
        while (int inc = dfs(src, INF)) flow += inc;
    }
    return flow;
}

int dx[] = {1, 0};
int dy[] = {0, 1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    src = n*m + 1;
    snk = n*m + 2;
    int t1 = 0, t2 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == '.') continue;
            int tp = (i + j) % 2;
            int qt;
            if(v[i][j] == 'H') qt = 1;
            else if(v[i][j] == 'O') qt = 2;
            else if(v[i][j] == 'N') qt = 3;
            else qt = 4;
            if(tp == 0) add_edge(src, i*m + j, qt), t1 += qt;
            else add_edge(i*m+j, snk, qt), t2 += qt;
            for(int k=0;k<2;k++){
                int xd = i + dx[k];
                int yd = j + dy[k];
                if(xd >= 0 && xd < n && yd >= 0 && yd < m){
                    if(tp == 0) add_edge(i*m + j, xd * m + yd, 1);
                    else add_edge(xd * m + yd, i * m + j, 1);
                }
            }
        }
    }
    if(t1 == t2 && t1 > 0 && t1 == dinic()) cout << "Valid\n";
    else cout << "Invalid\n";

}
