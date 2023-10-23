#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


void dijkstra(int src, vector<vector<ll>> &adj, vector<ll> &dist){
    dist.assign(dist.size(), INF_LL);
    dist[src] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto d = pq.top().first;
        auto u = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        for(int i=1;i<adj[u].size();i++){
            ll v = i, w = adj[u][i];
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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1)), dist1(n+1, vector<ll>(n+1)), dist2(n+1, vector<ll>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> dist[i][j];
            dist1[i][j] = dist[i][j] * a;
            dist2[i][j] = dist[i][j] * b + c;
        }
    }
    vector<ll> d1(n+1), d2(n+1);
    dijkstra(1, dist1, d1);
    dijkstra(n, dist2, d2);
    ll ans = INF_LL;
    for(int i=1;i<=n;i++){
        ans =  min(ans, d1[i] + d2[i]);
    }
    cout << ans << "\n";
}
