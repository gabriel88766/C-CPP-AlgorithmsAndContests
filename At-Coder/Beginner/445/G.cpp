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

int tp[305][305];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, a, b;
    cin >> n >> a >> b;
    vector<string> vs(n);
    for(int i=0;i<n;i++) cin >> vs[i];
    memset(tp, 0xFF, sizeof(tp));
    vector<pair<int, int>> pos = {{a, b}, {a, -b}, {-a, b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tp[i][j] == -1){
                queue<pair<int, int>> qp;
                qp.push({i, j});
                tp[i][j] = 0;
                while(qp.size()){
                    auto [x, y] = qp.front();
                    qp.pop();
                    for(auto [ca, cb] : pos){
                        if(x + ca >= 0 && x + ca < n && y + cb >= 0 && y + cb < n){
                            if(tp[x+ca][y+cb] == -1){
                                tp[x+ca][y+cb] = tp[x][y] ^ 1;
                                qp.push({x+ca, y+cb});
                            }else if(tp[x+ca][y+cb] == tp[x][y]){
                                assert(false);
                            }
                        }
                    }
                }
            }
        }
    }
    
    src = n*n, snk = n*n + 1;
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vs[i][j] == '#') continue;
            ans++;
            if(tp[i][j] == 0){
                add_edge(src, i*n + j, 1);
                for(auto [ca, cb] : pos){
                    if(i + ca >= 0 && i + ca < n && j + cb >= 0 && j + cb < n){
                        if(vs[i+ca][j+cb] == '.'){
                            add_edge(i*n+j, (i+ca)*n + j+cb, 1);
                        }
                    }
                }
            }else{
                add_edge(i*n + j, snk, 1);
            }
        }
    }
    dinic();
    vector<bool> vis(n * n + 2);
    queue<int> qp2;
    vis[src] = 0;
    qp2.push(src);
    while(qp2.size()){
        int cur = qp2.front();
        qp2.pop();
        for(auto k : g[cur]){
            if(edgs[k].c > edgs[k].f){
                if(!vis[edgs[k].v]){
                    vis[edgs[k].v] = true;
                    qp2.push(edgs[k].v);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vs[i][j] == '.'){
                if(tp[i][j] == 0 && vis[i*n + j]) vs[i][j] = 'o';
                else if(tp[i][j] == 1 && vis[i*n+j] == false) vs[i][j] = 'o';
            }
        }
        cout << vs[i] << "\n";
    }
}
