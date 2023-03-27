#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N];
vector<ll> adjw[N];

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
                pq.push({dist[v], v});
            }
        }
    }
}

bool func(pair<pair<int,int>,int> u, pair<pair<int,int>,int> v){
    if(u.first.second != v.first.second) return u.first.second < v.first.second;
    else return u < v;
}
bool func2(pair<pair<int,int>,int> u, pair<pair<int,int>,int> v){
    return u.second < v.second;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m;
    cin >> n >> m;
    ll sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    ll ans = abs(sx-fx) + abs(sy-fy);
    vector<pair<pair<int,int>,int>> fast(m+1);
    for(int i=1;i<=m;i++){
        cin >> fast[i].first.first >> fast[i].first.second;
        fast[i].second = i;
        adj[0].push_back(i);
        adjw[0].push_back(min(abs(fast[i].first.first - sx), abs(fast[i].first.second - sy)));
    }
    for(int j=0;j<2;j++){
        if(j == 0) sort(fast.begin()+1, fast.end());
        else sort(fast.begin()+1, fast.end(), func);
        for(int i=1;i<m;i++){
            ll d = min(abs(fast[i].first.first-fast[i+1].first.first), abs(fast[i].first.second-fast[i+1].first.second));
            adj[fast[i].second].push_back(fast[i+1].second);
            adj[fast[i+1].second].push_back(fast[i].second);
            adjw[fast[i].second].push_back(d);
            adjw[fast[i+1].second].push_back(d);
        }
    }
    dijkstra(0);
    for(int i=1;i<=m;i++){
        ll d = dist[fast[i].second] + abs(fast[i].first.first - fx) + abs(fast[i].first.second - fy);
        ans = min(ans, d);
    }
    cout << ans;
}
