#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<ll> adj[N], adjw[N], adjsp[N];
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
                adjsp[v].clear();
                adjsp[v].push_back(u);
                pq.push({dist[v], v});
            }else if(dist[v] == dist[u] + w){
                adjsp[v].push_back(u);
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
    for(int i=0;i<m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adjw[a].push_back(w);
    }
    dijkstra(1);
    vector<bool> vis(n+1, false);
    vector<int> av;
    queue<int> q;
    q.push(n);
    vis[n] = true;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        av.push_back(u);
        for(auto v : adjsp[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }
    sort(av.begin(), av.end(), [&](int u, int v){
        return dist[u] > dist[v];
    });
    vector<int> pos(n+1, 0);
    vector<int> inv(n+1, 0);
    for(int i=0;i<av.size();i++){
        pos[av[i]] = i;
        inv[i] = av[i];
    }
    vector<int> okp(av.size(), 0);
    for(auto u : av){
        for(auto v : adjsp[u]){
            int l = pos[u], r = pos[v];
            assert(r >= l);
            if(r-1 >= l+1){
                okp[l+1] += 1;
                okp[r] += -1;
            }
        }
    }
    for(int i=1;i<av.size();i++) okp[i] += okp[i-1];
    vector<int> ans;
    for(int i=0;i<av.size();i++) if(okp[i] == 0) ans.push_back(av[i]);
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}
