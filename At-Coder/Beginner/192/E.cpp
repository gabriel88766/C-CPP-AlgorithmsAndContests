//every single day a new different dijkstra
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<ll> adj[N], adjt[N], adjk[N];
ll dist[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for(int i=0;i<m;i++){
        int a, b, t, k;
        cin >> a >> b >> t >> k;
        adj[a].push_back(b);
        adjt[a].push_back(t);
        adjk[a].push_back(k);
        adj[b].push_back(a);
        adjt[b].push_back(t);
        adjk[b].push_back(k);
    }



    memset(dist, 63, sizeof(dist));
    dist[x] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, x});
    while(!pq.empty()){
        auto d = pq.top().first;
        auto u = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        for(int i=0;i<adj[u].size();i++){
            ll v = adj[u][i], k = adjk[u][i], w = adjt[u][i];
            ll r = d % k;
            if(r != 0) w += k - r;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    if(dist[y] != INF_LL) cout << dist[y] << "\n";
    else cout << "-1\n";
}
