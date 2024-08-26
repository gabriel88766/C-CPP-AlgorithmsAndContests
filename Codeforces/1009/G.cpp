#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
string x[N];


const int INF = 1e9;
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
        while (int inc = dfs(src, INF)) flow += inc;
    }
    return flow;
}

int tt[64][6];
int cuv[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    int m;
    cin >> s >> m;
    int n = s.size();
    for(int i=1;i<=n;i++) x[i] = "abcdef";
    for(int i=0;i<m;i++){
        int p;
        string xx;
        cin >> p >> xx;
        sort(xx.begin(), xx.end());
        x[p] = xx;
    }
    src = 70, snk = 71;
    vector<int> cnt(6, 0);
    for(int i=0;i<n;i++) cnt[s[i]-'a']++;
    for(int i=0;i<6;i++){
        add_edge(src, i, cnt[i]);
    }
    vector<int> cnt2(64, 0);
    for(int i=1;i<=n;i++){
        int cu = 0;
        for(auto c : x[i]){
            cu += (1 << (c-'a'));
        }
        cuv[i] = cu;
        cnt2[cu]++;
    }
    for(int i=0;i<64;i++){
        if(!cnt2[i]) continue;
        for(int k=0;k<6;k++){
            if(i & (1 << k)){
                add_edge(k, 6+i, cnt2[i]);
            }
        }
        add_edge(6+i, snk, cnt2[i]);
    }
    if(dinic() == n){
        string ans = "";
        for(int i=1;i<=n;i++){
            //I have the graph.
            //try to reach lowest letter in residual graph and change flow after this
            int bv = INF_INT;
            for(auto j : g[cuv[i]+6]){
                if(edgs[j].v >= 6) continue;
                int x = abs(edgs[j].f);
                if(x == tt[cuv[i]][edgs[j].v]) continue;
                if(edgs[j].v < bv){
                    bv = edgs[j].v;
                }
            }
            queue<int> q;
            vector<pair<int,int>> p(72, {-1, 0});
            q.push(cuv[i]+6);
            p[cuv[i]+6] = {bv, -1};//i want the lowest
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                for(auto j : g[u]){
                    cout.flush();
                    if(edgs[j].f == edgs[j].c) continue;
                    assert(edgs[j].v != snk || edgs[j].v != src);
                    // if(edgs[j].v == snk || edgs[j].v == src) continue;
                    if(edgs[j].v == cuv[i]+6 && u < p[cuv[i]+6].first){
                        p[cuv[i]+6] = {u, j};
                    }
                    if(u >= 6 && abs(edgs[j].f) == tt[u-6][edgs[j].v]) continue;
                    if(p[edgs[j].v].first == -1){
                        p[edgs[j].v] = {u, j};
                        q.push(edgs[j].v);
                    }
                }
            }
            if(p[cuv[i]+6].first == bv){
                ans += (char)('a' + bv);
                tt[cuv[i]][bv]++;
            }else{
                ans += (char)('a' + p[cuv[i]+6].first);
                int cur = cuv[i] + 6;
                do{
                    auto [pi, j] = p[cur];
                    edgs[j].f++;
                    edgs[j^1].f--;
                    cur = pi;
                }while(cur != cuv[i] + 6); 
                tt[cuv[i]][p[cuv[i]+6].first]++;
            }
            
            
        }
        cout << ans << "\n";
    }else cout << "Impossible\n";
    
}
