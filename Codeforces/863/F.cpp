#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 200;
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
    vector<ll> dist(n+1, INF_LL); //min or max?
    dist[src] = 0;
    queue<tuple<ll,ll,ll>> q;
    q.push({0, src, INF_LL});
    ll ans = 0;
    while(!q.empty()){
        auto [d, u, f] = q.front();
        q.pop();
        if(d > dist[u]) continue;
        for(auto k : g[u]){
            if(edgs[k].c == edgs[k].f) continue;
            if(dist[edgs[k].v] > dist[u] + edgs[k].w){ // > if min, < if max
                dist[edgs[k].v] = dist[u] + edgs[k].w;
                ll nxtf = min(f, edgs[k].c - edgs[k].f);
                q.push({dist[edgs[k].v], edgs[k].v, nxtf});
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
    if(flow == 0) return 0;
    vector<int> par(n+1);
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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int N, q;
    cin >> N >> q;
    vector<int> mn(N+1, 1), mx(N+1, N);
    for(int i=0;i<q;i++){
        int f, l, r, x;
        cin >> f >> l >> r >> x;
        if(f == 1){
            for(int i=l;i<=r;i++) mn[i] = max(mn[i], x);
        }else{
            for(int i=l;i<=r;i++) mx[i] = min(mx[i], x);
        }
    }
    bool ok = true;
    for(int i=1;i<=N;i++) if(mn[i] > mx[i]) ok = false;
    if(ok){
        src = 0, snk = 2*N + 1;
        n = snk;
        for(int i=1;i<=N;i++) add_edge(0, i, 1, 0);
        for(int i=1;i<=N;i++){
            for(int j=mn[i];j<=mx[i];j++) add_edge(i, N+j, 1, 0);
        }
        for(int j=1;j<=N;j++){
            for(int k=1;k<=50;k++){
                add_edge(N+j, snk, 1, 2*k-1);
            }
        }
        cout << MCMF(N) << "\n";
    }else  cout << "-1\n";
}
