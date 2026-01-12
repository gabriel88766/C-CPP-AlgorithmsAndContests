#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
ll dist[N];
vector<tuple<ll, ll, ll>> adj[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dist, 63, sizeof(dist));
    dist[1] = 0;
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a].push_back({b, c, d});
        adj[b].push_back({a, c, d});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while(pq.size()){
        auto [cd, u] = pq.top();
        pq.pop();
        if(cd != dist[u]) continue;
        for(auto [v, c, d] : adj[u]){
            ll x = sqrt(d);
            ll tt = INF_LL;
            for(ll y = max(dist[u], x - 3); y <= max(x + 3, dist[u]); y++){
                tt = min(tt, y - dist[u] + c + d/(y + 1));
            }
            if(dist[v] > dist[u] + tt){
                dist[v] = dist[u] + tt;
                pq.push({dist[v], v});
            }
        }
    }
    if(dist[n] != INF_LL) cout << dist[n] << "\n";
    else cout << "-1\n";
}
