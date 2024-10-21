#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 300, INF = 1e9;
struct edge {int v, c, f;};

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
    //for(int i=src;i<=snk;i++) h[i] = 0;
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

int dfs (int u, int flow) {
    if (!flow or u == snk) return flow;
    for (int &i = ptr[u]; i < g[u].size(); ++i) {
        edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
        int v = dir.v;
        if (h[v] != h[u] + 1)  continue;
        int inc = min(flow, dir.c - dir.f);
        inc = dfs(v, inc);
        if (inc) {
            dir.f += inc, rev.f -= inc;
            return inc;
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        memset(ptr, 0, sizeof ptr);
        //for(int i=src;i<=snk;i++) ptr[i] = 0;
        while (int inc = dfs(src, INF)) flow += inc;
    }
    return flow;
}

void clear(){
    edgs.clear();
    for(int i=0;i<=snk;i++) g[i].clear();

}

const int M = 2e5+3;
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
    int n, k;
    cin >> n >> k;
    vector<tuple<int,int,int>> vt(n+1);
    for(int i=1;i<=n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        vt[i] = {a, b, c};
    }
    auto get_pow = [&](int l){
        map<int, int> mp;
        for(auto &[a, b, c] : vt){
            if(c > l) continue;
            if(b == 1) mp[b] = max(mp[b], a);
            else mp[b] += a;
        }
        vector<pair<int,int>> va;
        vector<pair<int,int>> vb;
        for(auto [k, v] : mp){
            if(k % 2) va.push_back({k, v});
            else vb.push_back({k, v});
        }
        int sa = va.size();
        int sb = vb.size();
        src = 0;
        snk = sa + sb + 1;
        clear();
        ll S = 0;
        for(int i=1;i<=sa;i++){
            add_edge(0, i, va[i-1].second);
            S += va[i-1].second;
        }
        for(int i=1;i<=sb;i++){
            add_edge(sa+i, snk, vb[i-1].second);
            S += vb[i-1].second;
        }
        for(int i=1;i<=sa;i++){
            for(int j=1;j<=sb;j++){
                if(!p[va[i-1].first + vb[j-1].first]){
                    add_edge(i, sa+j, INF);
                }
            }
        }
        return S - dinic();
    };
    for(int i=1;i<=n;i++){
        // cout << i << " : " << get_pow(i) << "\n";
    }
    int ans = -1;
    if(get_pow(n) >= k){
        int lo = 1, hi = n;
        while(lo != hi){
            int mid = lo + (hi - lo)/2;
            if(get_pow(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }else cout << "-1\n";
}
