#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int  N = 2e5+3;
vector<int> adj[N];
int dist[N];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void dijkstra(){
    while(!pq.empty()){
        auto d = pq.top().first;
        auto u = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        for(int i=0;i<adj[u].size();i++){
            ll v = adj[u][i];
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
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
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dist, 63, sizeof(dist));
    for(int i=0;i<k;i++){
        int p, h;
        cin >> p >> h;
        dist[p] = -h;
        pq.push({dist[p], p});
    }
    dijkstra();
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(dist[i] <= 0) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
}
