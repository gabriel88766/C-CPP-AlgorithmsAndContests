#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;   
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


vector<ll> adj[N], adjw[N];
vector<ll> adj2[N], adjw2[N];
ll dist[50][N];

void dijkstra(int src, int j){
    memset(dist[j], 63, sizeof(dist[j]));
    dist[j][src] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto d = pq.top().first;
        auto u = pq.top().second;
        pq.pop();
        if(d > dist[j][u]) continue;
        for(int i=0;i<adj[u].size();i++){
            ll v = adj[u][i], w = adjw[u][i];
            if(dist[j][v] > dist[j][u] + w){
                dist[j][v] = dist[j][u] + w;
                pq.push({dist[j][v], v});
            }
        }
    }
}

const int M = 20; 
int rt = 1, anc[N][M], h[N];
ll dis[N][M];

void dfs(int u, int par){ 
    anc[u][0] = par;
    h[u] = h[par] + 1;
    for(int i=0;i<adj2[u].size();i++){
        if(adj2[u][i] != par){
            dis[adj2[u][i]][0] = adjw2[u][i];
            dfs(adj2[u][i], u);
        }
    } 
}

void build(int n){
    h[0] = -1;
    dfs(rt, 0);
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
            dis[i][j] = dis[i][j-1] + dis[anc[i][j-1]][j-1];
        }
    }
}

ll lca(int a, int b){ 
    ll ans = 0;
    if(h[a] > h[b]) swap(a, b);
    int diff = h[b] - h[a];
    for(int i = M-1; i>=0;i--) if(diff & (1 << i)){
        ans += dis[b][i];
        b = anc[b][i];
    }
    if(a == b) return ans;
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]){
            ans += dis[a][i] + dis[b][i];
            a = anc[a][i], b = anc[b][i];
        }
    }
    return ans + dis[a][0] + dis[b][0];
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> chk;
    init();
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(get(a) == get(b)){
            chk.push_back(a);
            chk.push_back(b);
        }else{
            unite(a, b);
            //for tree
            adj2[a].push_back(b);
            adjw2[a].push_back(c);
            adj2[b].push_back(a);
            adjw2[b].push_back(c);
        }
        adj[a].push_back(b);
        adjw[a].push_back(c);
        adj[b].push_back(a);
        adjw[b].push_back(c);
    }
    build(n);
    sort(chk.begin(), chk.end());
    chk.resize(unique(chk.begin(), chk.end()) - chk.begin());
    for(int i=0;i<chk.size();i++) dijkstra(chk[i], i);
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        ll ans = lca(a, b);
        for(int j=0;j<chk.size();j++){
            ans = min(ans, dist[j][a] + dist[j][b]);
        }
        cout << ans << "\n";
    }
}
