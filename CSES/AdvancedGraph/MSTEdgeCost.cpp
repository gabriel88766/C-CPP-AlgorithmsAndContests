#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 20;   
int p[N], sz[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}

struct Edge{
    int a, b, w, j;
    bool operator< (Edge v){
        if(w != v.w) return w < v.w;
        else return make_pair(a,b) < make_pair(v.a,v.b);
    }
};

vector<Edge> edges;
vector<int> adj[N], adjw[N];
int ink[N];
ll tw = 0;

void kruskal(){
    sort(edges.begin(), edges.end());
    init();
    for(auto e : edges){
        if(get(e.a) != get(e.b)){
            adj[e.a].push_back(e.b);
            adjw[e.a].push_back(e.w);
            adj[e.b].push_back(e.a);
            adjw[e.b].push_back(e.w);
            ink[e.j] = true;
            unite(e.a, e.b);
            tw += e.w;
        }
    }
}


int rt = 1, anc[N][M], h[N], me[N][M];

void dfs(int u, int par){ 
    anc[u][0] = par;
    h[u] = h[par] + 1;
    for(int i=0;i<adj[u].size();i++){
        auto &x = adj[u][i];
        auto &w = adjw[u][i];
        if(x != par){
            dfs(x, u);
        }else{
            me[u][0] = w;
        }
    } 
}

void build(int n){
    h[0] = -1;
    dfs(rt, 0);
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
            me[i][j] = max(me[i][j-1], me[anc[i][j-1]][j-1]);
        }
    }
}

int lca(int a, int b){ 
    if(h[a] > h[b]) swap(a, b);
    int diff = h[b] - h[a];
    int mx = 0;
    for(int i = M-1; i>=0;i--) if(diff & (1 << i)) {mx = max(mx, me[b][i]); b = anc[b][i];}
    if(a == b) return mx;
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]){
            mx = max({mx, me[a][i], me[b][i]});
            a = anc[a][i], b = anc[b][i];
        }
    }
    mx = max({mx, me[a][0], me[b][0]});
    return mx;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edg;
    for(int i=0;i<m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        edg.push_back({a, b, w});
        edges.push_back({a, b, w, i});
    }
    kruskal();
    build(n);
    for(int j=0;j<edg.size();j++){
        cout << tw + get<2>(edg[j]) - lca(get<0>(edg[j]), get<1>(edg[j])) << "\n";
    }
}
