#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<ll> adj[N], adjw[N];
ll wv[N];
ll dist[N];

void dijkstra(int src){
    memset(dist, 63, sizeof(dist));
    dist[src] = wv[src];
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({wv[src], src});
    while(!pq.empty()){
        auto d = pq.top().first;
        auto u = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        for(int i=0;i<adj[u].size();i++){
            ll v = adj[u][i], w = adjw[u][i];
            if(dist[v] > dist[u] + w + wv[v]){
                dist[v] = dist[u] + w + wv[v];
                pq.push({dist[v], v});
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> wv[i];
    for(int i=0;i<m;i++){
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adjw[a].push_back(w);
        adj[b].push_back(a);
        adjw[b].push_back(w);
    }
    dijkstra(1);
    for(int i=2;i<=n;i++) cout << dist[i] << " ";
    cout << "\n";
}   
