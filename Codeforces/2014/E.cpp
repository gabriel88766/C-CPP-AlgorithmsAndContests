#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, h;
        cin >> n >> m >> h;
        vector<vector<ll>> adj(n+1), adjw(n+1);
        vector<bool> hh(n+1, false);
        for(int i=0;i<h;i++){
            int x;
            cin >> x;
            hh[x] = true;
        }
        for(int i=0;i<m;i++){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(v);
            adjw[u].push_back(w);
            adj[v].push_back(u);
            adjw[v].push_back(w);
        }
        vector<vector<ll>> d1(n+1, vector<ll>(2, INF_LL)), d2(n+1, vector<ll>(2, INF_LL));
        auto dijkstra = [&](vector<vector<ll>> &dist, int src){
            dist[src][0] = 0;
            priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> pq;
            pq.push({0, src, 0});
            while(!pq.empty()){
                auto [d, u, x] = pq.top();
                pq.pop();
                if(d > dist[u][x]) continue;
                for(int i=0;i<adj[u].size();i++){
                    ll v = adj[u][i], w = adjw[u][i];
                    if(x == 1) w /= 2;
                    if(dist[v][x] > dist[u][x] + w){
                        dist[v][x] = dist[u][x] + w;
                        pq.push({dist[v][x], v, x});
                    }
                }
                if(hh[u] && dist[u][1] > dist[u][0]){
                    dist[u][1] = dist[u][0];
                    pq.push({dist[u][1], u, 1});
                }
            }
        };
        dijkstra(d1, 1);
        dijkstra(d2, n);
        ll ans = INF_LL;
        for(int i=1;i<=n;i++){
            ans = min(ans, max(min(d1[i][0], d1[i][1]), min(d2[i][0], d2[i][1])));
        }
        if(ans == INF_LL) cout << "-1\n";
        else cout << ans << "\n";
    }
}
