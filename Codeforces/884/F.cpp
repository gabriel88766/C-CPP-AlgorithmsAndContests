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
    vector<ll> dist(n+1, -INF_LL); //min or max?
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
            if(dist[edgs[k].v] < dist[u] + edgs[k].w){ // > if min, < if max
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

//Flow bounded.
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m;
    string s;
    cin >> m >> s;
    vector<int> v(m+1);
    s = " " + s;
    for(int i=1;i<=m;i++) cin >> v[i];
    n = snk = m/2+26+1;
    src = 0;
    vector<int> cnt(26, 0);
    for(int i=1;i<=m;i++) cnt[s[i]-'a']++;
    for(int i=1;i<=26;i++) {
        add_edge(0, i, cnt[i-1], 0);
    }
    for(int i=1;i<=m/2;i++){
        for(int j=1;j<=26;j++){
            int val = 0;
            if(s[i] == 'a'+j-1) val = max(val, v[i]);
            if(s[m-i+1] == 'a'+j-1) val = max(val, v[m-i+1]);
            add_edge(j, 26+i, 1, val);
        }
        add_edge(26+i, m/2+26+1, 2, 0);
    }
    cout << MCMF(m) << "\n";
}
