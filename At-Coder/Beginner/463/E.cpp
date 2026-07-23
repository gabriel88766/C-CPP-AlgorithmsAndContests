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
    int n, m;
    ll y;
    cin >> n >> m >> y;
    vector<vector<ll>> adj(n+1), adjw(n+1);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    auto dijkstra = [&](vector<ll> &dist){
        // memset(dist, 63, sizeof(dist)); //done outside
        // dist[src] = 0; //done outside
        // pq.push({0, src}); //done outside
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
    };
    for(int i=1;i<=m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adj[b].push_back(a);
        adjw[a].push_back(w);
        adjw[b].push_back(w);
    }
    vector<ll> d1(n+1, INF_LL), d2(n+1, INF_LL), xv(n+1);
    for(int i=1;i<=n;i++){
        cin >> xv[i];
        d2[i] = y + xv[i];
    }
    pq.push({0, 1});
    d1[1] = 0;
    dijkstra(d1);
    for(int i=1;i<=n;i++){
        pq.push({d2[i], i});
    }
    dijkstra(d2);
    auto d3 = d1;
    ll mn = INF_LL;
    for(int i=1;i<=n;i++){
        mn = min(mn, d1[i] + xv[i]);
    }
    //opt 0, only edges, opt 1, go to some vertex (mn), take a warp, go to dest (d2)
    for(int i=2;i<=n;i++){
        cout << min(d1[i], mn + d2[i]) << " ";
    }
    cout << "\n";
}
