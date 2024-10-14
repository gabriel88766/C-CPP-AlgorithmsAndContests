#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2e5+3;
vector<ll> adj[N], adjw[N], par[N], adj2[N];
ll dist[N];
map<pair<int,int>, int> mp;
int ans[N];

void dijkstra(int src){
    memset(dist, 63, sizeof(dist));
    dist[src] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto d = pq.top().first;
        auto u = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        for(int i=0;i<adj[u].size();i++){
            ll v = adj[u][i], w = adjw[u][i];
            if(dist[v] > dist[u] + w){
                par[v].clear();
                par[v].push_back(u);
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }else if(dist[v] == dist[u] + w){
                par[v].push_back(u);
            }
        }
    }
}


int in[N], low[N], cnt = 0;
vector<pair<int,int>> bdgs;

void dfs_bridge(int u, int p = -1){
    low[u] = in[u] = ++cnt;
    for(auto v: adj2[u]){
        if(v == p) continue;
        if(!in[v]){
            dfs_bridge(v, u);
            if(low[v] == in[v]) bdgs.push_back({u, v});
        }
        low[u] = min(low[u], low[v]);
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adjw[a].push_back(w);
        adj[b].push_back(a);
        adjw[b].push_back(w);
        mp[{a, b}] = i;
    }
    dijkstra(1);    
    queue<int> q;
    vector<bool> vis(n+1, false);
    q.push(n);
    vis[n] =true;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : par[u]){
            adj2[u].push_back(v);
            adj2[v].push_back(u);
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }
    dfs_bridge(1);
    for(auto [a, b] : bdgs){
        if(a > b) swap(a, b);
        ans[mp[{a, b}]] = 1;
    }
    for(int i=1;i<=m;i++){
        if(ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
}
