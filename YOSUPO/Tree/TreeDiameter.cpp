#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3;
vector<ll> adj[N], adjw[N];
ll d[N];
int n, p[N];

void dijkstra(int src){
    d[src] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto dist = pq.top().first;
        auto u = pq.top().second;
        pq.pop();
        if(dist > d[u]) continue;
        for(int i=0;i<adj[u].size();i++){
            ll v = adj[u][i], w = adjw[u][i];
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                p[v] = u;
                pq.push({d[v], v});
            }
        }
    }
}

pair<int,int> diameter(){ //node first to second is the diameter.
    memset(d, 63, sizeof(d));
    dijkstra(0);
    int fart1 = 1, fart2 = 1;
    ll maxd = 0;
    for(int i=1;i<n;i++) if(d[i] > maxd) maxd = d[i], fart1 = i;
    memset(d, 63, sizeof(d));
    dijkstra(fart1);
    maxd = 0;
    for(int i=0;i<n;i++) if(d[i] > maxd) maxd = d[i], fart2 = i;
    return {fart1, fart2};
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        adjw[a].push_back(c);
        adjw[b].push_back(c);
    }
    auto [p1, p2] = diameter();
    int cur = p2;
    vector<int> v = {cur};
    while(cur != p1){
        cur = p[cur];
        v.push_back(cur);
    }
    cout << d[p2] << " " << v.size() << "\n";
    for(auto x : v) cout << x << " ";
    cout << "\n";
}
