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
    vector<ll> dist(n+1, INF_LL); //if min INF_LL, if max -INF_LL
    dist[src] = 0;
    queue<tuple<ll,ll,ll>> q;
    q.push({0, src, INF_LL});
    ll ans = 0;
    while(!q.empty()){
        auto [d, u, f] = q.front();
        q.pop();
        if(d != dist[u]) continue;
        for(auto k : g[u]){
            if(edgs[k].c == edgs[k].f) continue;
            assert(u != edgs[k].v);
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

ll MCMF(){
    vector<int> par(n+1);
    ll curflow = 0;
    ll cost = 0;
    ll next_flow;
    ll mxc = 0;
    while(next_flow = shortestpath(par)){
        curflow += next_flow;
        int cur = snk;
        while(cur != src){
            int k = par[cur];
            edgs[k].f -= next_flow;
            edgs[k^1].f += next_flow;
            cost += edgs[k^1].w * next_flow;
            cur = edgs[k].v;
        }
        mxc = min(mxc, cost);
    }
    return mxc;
}

ll gr[2005][2005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    
    int h, w;
    cin >> h >> w;
    ll ans = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> gr[i][j];
            ans += gr[i][j];
        }
    }
    src = h*w;
    snk = h*w + 1;
    n = h*w + 2;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if((i + j) % 2){
                add_edge(src, i*w + j, 1, 0);
                if(j + 1 != w){
                    add_edge(i*w + j, i*w + j + 1, 1, (gr[i][j] + gr[i][j+1]));
                }
                if(i + 1 != h){
                    add_edge(i*w + j, i*w + j + w, 1, (gr[i][j] + gr[i+1][j]));
                }
            }else{
                add_edge(i*w+j, snk, 1, 0);
                if(j + 1 != w){
                    add_edge(i*w + j + 1, i*w + j, 1, (gr[i][j] + gr[i][j+1]));
                }
                if(i + 1 != h){
                    add_edge(i*w + j + w, i*w + j, 1, (gr[i][j] + gr[i+1][j]));
                }
            }
        }
    }
    cout << ans - MCMF() << "\n";
    

}
