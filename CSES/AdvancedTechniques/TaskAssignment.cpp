#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
struct edge {ll v, c, f, w;};
vector<edge> edgs;
vector<int> g[N];
void add_edge (ll u, ll v, ll c, ll w) {
    int k = edgs.size();
    edgs.push_back({v, c, 0, w});
    edgs.push_back({u, 0, 0, -w});
    g[u].push_back(k);
    g[v].push_back(k+1);
}
int src, snk, n;

ll shortestpath(vector<int> &par){
    fill(par.begin(), par.end(), -1);
    vector<ll> dist(2*n+2, INF_LL);
    dist[src] = 0;
    queue<tuple<ll,ll,ll>> pq;
    pq.push({0, src, INF_LL});
    ll ans = 0;
    while(!pq.empty()){
        auto [d, u, f] = pq.front();
        pq.pop();
        if(d > dist[u]) continue;
        for(auto k : g[u]){
            if(edgs[k].c == edgs[k].f) continue;
            if(dist[edgs[k].v] > dist[u] + edgs[k].w){
                dist[edgs[k].v] = dist[u] + edgs[k].w;
                ll nxtf = min(f, edgs[k].c - edgs[k].f);
                pq.push({dist[edgs[k].v], edgs[k].v, nxtf});
                par[edgs[k].v] = k^1;
                if(edgs[k].v == snk){
                     ans = nxtf;
                }
            }
        }
    }
    return ans;
}

ll MCMF(int flow){
    vector<int> par(2*n+2);
    ll curflow = 0;
    ll cost = 0;
    ll next_flow;
    while(next_flow = shortestpath(par)){
        next_flow = min(next_flow, flow - curflow);
        curflow += next_flow;
        int cur = snk;
        while(cur != src){
            int k = par[cur];
            edgs[k].f -= next_flow;
            edgs[k^1].f += next_flow;
            cost += edgs[k^1].w * next_flow;
            cur = edgs[k].v;
        }
        if(curflow == flow) return cost;
    }
    return -1;
}

//Flow bounded.
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    src = 0, snk = 2*n+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int cost;
            cin >> cost;
            add_edge(i, n + j, 1, cost);
        }
    }
    for(int i=1;i<=n;i++){
        add_edge(0, i, 1, 0);
        add_edge(n+i, 2*n+1, 1, 0);
    }
    cout << MCMF(n) << "\n";
    for(int i=1;i<=n;i++){
        for(auto k : g[i]){
            if(edgs[k].v != 0 && edgs[k].f == 1) cout << i << " " << edgs[k].v-n << "\n";
        }
    }
}
