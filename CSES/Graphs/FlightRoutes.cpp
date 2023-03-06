#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<ll> adj[N], adjw[N];
ll dist[N][10];

void dijkstra(ll src){
    memset(dist, 63, sizeof(dist));
    dist[src][0] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto d = pq.top().first;
        auto u = pq.top().second;
        pq.pop();
        if(d > dist[u][9]) continue;
        for(int i=0;i<adj[u].size();i++){
            ll v = adj[u][i], w = adjw[u][i];
            for(int j=0;j<10;j++){
                if(dist[v][j] > d + w){
                    for(int k=9;k>=(j+1);k--) dist[v][k] = dist[v][k-1];
                    dist[v][j] = d + w;
                    pq.push({dist[v][j], v});
                    break;
                }
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b);
        adjw[a].emplace_back(w);
    }
    dijkstra(1);
    for(int i=0;i<k;i++) cout << dist[n][i] << " ";
}
