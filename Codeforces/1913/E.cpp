#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 55;
struct edge {int v, c, f, w;};
vector<edge> edgs;
vector<int> g[10005];
int cost[N][N];
void add_edge (int u, int v, int c, int w) {
    int k = edgs.size();
    edgs.push_back({v, c, 0, w});
    edgs.push_back({u, 0, 0, -w});
    g[u].push_back(k);
    g[v].push_back(k+1);
}
int src, snk;
 
int shortestpath(vector<int> &par){
    fill(par.begin(), par.end(), -1);
    vector<int> dist(par.size(), INF_INT);
    dist[src] = 0;
    queue<tuple<int,int,int>> q;
    q.push({0, src, INF_INT});
    int ans = 0;
    while(!q.empty()){
        auto [d, u, f] = q.front();
        q.pop();
        
        if(d != dist[u]) continue;
        for(auto k : g[u]){
            if(edgs[k].c == edgs[k].f) continue;
            if(dist[edgs[k].v] > dist[u] + edgs[k].w){
                dist[edgs[k].v] = dist[u] + edgs[k].w;
                int nxtf = min(f, edgs[k].c - edgs[k].f);
                q.push({dist[edgs[k].v], edgs[k].v, nxtf});
                par[edgs[k].v] = k^1;
                if(edgs[k].v == snk){
                     ans = nxtf;
                }
            }
        }
    }
    return ans;
}
 
int MCMF(int flow, int n){
    vector<int> par(n+1);
    int curflow = 0;
    int cost = 0;
    int next_flow;
    while(next_flow = shortestpath(par)){
        next_flow = min(next_flow, flow - curflow);
        curflow += next_flow;
        int cur = snk;
        while(cur != src){
            int k = par[cur];
            edgs[k].f -= next_flow;
            edgs[k^1].f += next_flow;
            cost += edgs[k^1].w * next_flow;
            cur = edgs[k].v;
        }
        if(curflow == flow) return cost;
    }
    if(curflow == flow) return cost;
    else return -INF_INT;
}
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    int f1 = 0, f2 = 0;
    vector<int> a(n+1), b(m+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> cost[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
        f1 += a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> b[i];
        f2 += b[i];
    }
    if(f1 != f2){
        cout << "-1\n";
    }else{
        src = 0, snk = n+m+1;        
        for(int i=1;i<=n;i++) add_edge(0, i, a[i], 0);
        for(int i=1;i<=m;i++) add_edge(n+i, n+m+1, b[i], 0);
        int curcst = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int w = cost[i][j] ? -1 : 1;
                curcst += cost[i][j];
                add_edge(i, n+j, 1, w);
            }
        }
        int ansc = MCMF(f1, n+m+1);
        if(ansc != -INF_INT){
            cout << ansc + curcst << "\n";
        }else cout << "-1\n";
    }
}