#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//O((V+E) logE) tested https://cses.fi/problemset/task/1671
const int N = 2e5+3;
vector<ll> adj[N], adjw[N];
ll dist[N], minf[N], maxf[N], qnt[N];

void dijkstra(int src){
    memset(dist, 63, sizeof(dist));
    dist[src] = minf[src] = maxf[src] = 0;
    qnt[src] = 1;
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
                dist[v] = dist[u] + w;
                maxf[v] = maxf[u] + 1;
                minf[v] = minf[u] + 1;
                qnt[v] = qnt[u];
                pq.push({dist[v], v});
            }else if(dist[v] == dist[u] + w){
                minf[v] = min(minf[v], minf[u]+1);
                maxf[v] = max(maxf[v], maxf[u]+1);
                qnt[v] = (qnt[v] + qnt[u]) % MOD;
            }
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b);
        adjw[a].emplace_back(w);
    }
    dijkstra(1);
    cout << dist[n] << " " << qnt[n] << " " << minf[n] << " " << maxf[n];
}
