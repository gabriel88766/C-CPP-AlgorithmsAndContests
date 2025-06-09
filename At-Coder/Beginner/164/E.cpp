#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dist[51][5001]; //5000 coins is the highest amount that makes any sense to get. trip must have at most 2n cities
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dist, 63, sizeof(dist));
    int n, m, s;
    cin >> n >> m >> s;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    pq.push({0, 1, min(s, 5000)});
    dist[1][min(s, 5000)] = 0;
    vector<vector<tuple<ll, ll, ll>>> adj(n+1);
    for(int i=1;i<=m;i++){
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        adj[u].push_back({v, a, b});
        adj[v].push_back({u, a, b});
    }
    vector<pair<ll, ll>> cst(n+1);
    for(int i=1;i<=n;i++){
        cin >> cst[i].first >> cst[i].second;
    }
    while(pq.size()){
        auto [d, u, cs] =  pq.top();
        pq.pop();
        // cout << pq.size() << " ";
        if(d > dist[u][cs]) continue;
        auto [x, y] = cst[u];
        if(dist[u][min(5000LL, cs + x)] > dist[u][cs] + y){
            dist[u][min(5000LL, cs + x)] = dist[u][cs] + y;
            pq.push({dist[u][min(5000LL, cs+x)], u, min(5000LL, cs + x)});
        }
        for(auto &[v, a, b] : adj[u]){
            if(cs >= a && dist[v][cs - a] > dist[u][cs] + b){
                dist[v][cs - a] = dist[u][cs] + b;
                pq.push({dist[v][cs - a], v, cs - a});
            }
        }
    }
    for(int i=2;i<=n;i++){
        ll ans = INF_LL;
        for(int j=0;j<=5000;j++) ans = min(ans, dist[i][j]);
        cout << ans << "\n";
    }

}
