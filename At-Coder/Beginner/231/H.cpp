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

void clear(){ 
    for(int i=0;i<=snk;i++){ g[i].clear();}
    
    edgs.clear(); 
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int h, w, m;
    cin >> h >> w >> m;
    vector<vector<ll>> cv(h+1, vector<ll>(w+1, INF_LL));
    for(int i=1;i<=m;i++){
        int x, y, c;
        cin >> x >> y >> c;
        cv[x][y] = c;
    }
    vector<int> ch(h+1), cw(w+1);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(cv[i][j] != INF_LL){
                ch[i]++;
                cw[j]++;
            }
        }
    }
    set<int> sh, sw;
    for(int i=1;i<=h;i++) sh.insert(i);
    for(int i=1;i<=w;i++) sw.insert(i);
    ll cst = 0;
    for(int i=1;i<=h;i++){
        if(ch[i] == 1){
            for(int j=1;j<=w;j++){
                if(cv[i][j] != INF_LL){
                    cst += cv[i][j];
                    sh.erase(i);
                    sw.erase(j);
                }
            }
        }
    }
    for(int j=1;j<=w;j++){
        if(cw[j] == 1){
            for(int i=1;i<=h;i++){
                if(cv[i][j] != INF_LL && ch[i] != 1){
                    cst += cv[i][j];
                    sh.erase(i);
                    sw.erase(j);
                }
            }
        }
    }
    //now work on sh and sw;
    vector<int> x, y;
    for(auto xx : sh) x.push_back(xx);
    for(auto xx : sw) y.push_back(xx);

    int tt = x.size() + y.size();
    src = 0, n = snk = tt + 3;
    int i1 = tt + 1, i2 = tt + 2;
    ll ans = INF_LL;   
    
    for(int i=max(x.size(),y.size());i<=tt;i++){
        clear();
        add_edge(src, i1, max(0, (int)y.size() - (int)x.size()) + i - max(y.size(), x.size()), 0); 
        for(int j=0; j < y.size();j++){
            add_edge(x.size() + j + 1, snk, 1, 0);
            ll mn = INF_LL;
            for(int i=1;i<=h;i++) mn = min(mn, cv[i][y[j]]);    
            add_edge(i1, x.size() + j + 1, 1, mn);
        }
        add_edge(i2, snk, max(0, (int)x.size() - (int)y.size()) + i - max(y.size(), x.size()), 0);
        for(int i=0;i<x.size();i++){
            add_edge(src, i + 1, 1, 0);
            ll mn = INF_LL;
            for(int j=1;j<=w;j++) mn = min(mn, cv[x[i]][j]);
            add_edge(i + 1, i2, 1, mn);
        }



        for(int i=0;i<x.size();i++){
            for(int j=0;j<y.size();j++){
                add_edge(i + 1, x.size() + j + 1, 1, cv[x[i]][y[j]]);
            }
        }
        ll cur = MCMF(i);
        if(cur >= ans) break;
        ans = min(ans, cur);
    }
    cout << ans + cst << "\n";
    



}
