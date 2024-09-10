#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
vector<ll> adj[N], adjw[N];
map<pair<int,int>, int> edg;
ll dist[N], par[N];

vector<int> adj2[N], adji[N];

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
        int a = u, b = par[u];
        if(a > b) swap(a, b);
        adj2[par[u]].push_back(u);
        adji[par[u]].push_back(edg[{a, b}]);
        for(int i=0;i<adj[u].size();i++){
            ll v = adj[u][i], w = adjw[u][i];
            if(dist[v] > dist[u] + w){
                par[v] = u;
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
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        if(a > b) swap(a, b);
        edg[{a, b}] = i;
        adj[a].push_back(b);
        adjw[a].push_back(w);
        adj[b].push_back(a);
        adjw[b].push_back(w);
    }
    dijkstra(1);
    queue<int> q;
    q.push(1);
    vector<int> ans;
    int cnt = 0;
    while(q.size() && cnt < k){
        auto u = q.front();
        q.pop();
        for(int i=0;i<adj2[u].size();i++){
            int j = adji[u][i];
            int v = adj2[u][i];
            cnt++;
            ans.push_back(j);
            q.push(v);
            if(cnt == k) break;
        }
    }
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}
