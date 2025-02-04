#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
const ll INF = 1e18;
struct edge {ll v, c, f;};

int src, snk, h[N], ptr[N];
vector<edge> edgs;
vector<int> g[N];

void add_edge (int u, int v, int c) {
    int k = edgs.size();
    edgs.push_back({v, c, 0});
    edgs.push_back({u, 0, 0});
    g[u].push_back(k);
    g[v].push_back(k+1);
}

bool bfs() {
    memset(h, 0, sizeof h);
    queue<int> q;
    h[src] = 1;
    q.push(src);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i : g[u]) {
            int v = edgs[i].v;
            if (!h[v] && edgs[i].f < edgs[i].c)
                q.push(v), h[v] = h[u] + 1;
        }
    }
    return h[snk];
}

ll dfs (int u, ll flow) {
    if (!flow or u == snk) return flow;
    for (int &i = ptr[u]; i < g[u].size(); ++i) {
        edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
        int v = dir.v;
        if (h[v] != h[u] + 1)  continue;
        ll inc = min(flow, dir.c - dir.f);
        inc = dfs(v, inc);
        if (inc) {
            dir.f += inc, rev.f -= inc;
            return inc;
        }
    }
    return 0;
}

ll dinic() {
    ll flow = 0;
    while (bfs()) {
        memset(ptr, 0, sizeof ptr);
        while (ll inc = dfs(src, INF)) flow += inc;
    }
    return flow;
}

const int M = 2e7+5;
int p[M]; // 0 if prime, 1 if not prime
void sieve(){
    for(ll i=2; i<M; i++){
        if(!p[i]){
            for(ll j = i*i; j < M; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int nv;
    cin >> nv;
    vector<pair<int,int>> ve, vo;
    int qt1 = 0;
    for(int i=1;i<=nv;i++){
        int x, y;
        cin >> x >> y;
        if(x % 2 == 0) ve.push_back({x, y});
        else if(x != 1) vo.push_back({x, y});
        else qt1 = y;
    }
    vo.push_back({1, 0});
    sort(vo.begin(), vo.end());
    sort(ve.begin(), ve.end());
    //dinic from even to odd
    int o = vo.size(), e = ve.size();
    src = 0;
    snk = o + e + 1;
    int ed;
    for(int i=0;i<vo.size();i++){
        if(i == 0) ed = edgs.size();
        add_edge(0, i+1, vo[i].second);
    }
    for(int i=0;i<ve.size();i++){
        add_edge(o + i + 1, o + e + 1, ve[i].second);
    }
    for(int i=0;i<vo.size();i++){
        for(int j=0;j<ve.size();j++){
            if(!p[vo[i].first + ve[j].first]) add_edge(i+1, o+j+1, 1e9);
        }
    }
    ll ans = dinic();
    edgs[ed].c = qt1;
    ll ans2 = dinic();
    qt1 -= ans2;
    ans += qt1/2 + ans2;



    cout << ans << "\n";
}
