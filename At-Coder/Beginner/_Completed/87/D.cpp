#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<ll> adj[N], adjw[N];
ll dist[N];
int indg[N];

bool dijkstra(int src){
    dist[src] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto d = pq.top().first;
        auto u = pq.top().second;
        pq.pop();
        if(d > dist[u]) return false;
        for(int i=0;i<adj[u].size();i++){
            ll v = adj[u][i], w = adjw[u][i];
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }else if(dist[v] < dist[u] + w) return false;
        }
    }
    return true;
}

int p[N], sz[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}

struct Edge{
    int a, b, c;
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    memset(dist, 63, sizeof(dist));
    vector<Edge> v;
    init();
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(c != 0) v.push_back({a,b,c});
        else unite(a, b);
    }
    bool ok = true;
    for(auto x : v){
        if(get(x.a) == get(x.b)){
            ok = false;
        }else{
            adj[get(x.a)].push_back(get(x.b));
            adjw[get(x.a)].push_back(x.c);
            indg[get(x.b)]++;
        }
    }
    for(int i=1;i<=n;i++){ 
        if(!indg[i] && i == get(i)) ok &= dijkstra(i);
    }
    for(int i=1;i<=n;i++){ 
        if(dist[i] == INF_LL && get(i) == i) ok &= false;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
