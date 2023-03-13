#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<ll> adj[N], adjw[N];
ll dist[N];

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
                dist[v] = dist[u] + w;
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
    int n, q, k;   
    cin >> n;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adjw[a].push_back(c);
        adj[b].push_back(a);
        adjw[b].push_back(c);
    }
    cin >> q >> k;
    dijkstra(k);
    for(int i=1;i<=q;i++){
        int a,b;
        cin >> a >> b;
        cout << dist[a] + dist[b] << "\n";
    }
}
