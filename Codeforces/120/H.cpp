#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1, INF = 1e9;
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

string str[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    src = 0;
    int cn = n;
    map<string, int> mp;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        vector<string> ps;
        for(int j=0;j<s.size();j++){
            string cs;
            cs += s[j];
            ps.push_back(cs);
        }
        for(int j=0;j<s.size();j++){
            for(int k=j+1;k<s.size();k++){
                string cs;
                cs += s[j];
                cs += s[k];
                ps.push_back(cs);
            }
        }
        for(int j=0;j<s.size();j++){
            for(int k=j+1;k<s.size();k++){
                for(int l=k+1;l<s.size();l++){
                    string cs;
                    cs += s[j];
                    cs += s[k];
                    cs += s[l];
                    ps.push_back(cs);
                }
            }
        }
        for(int j=0;j<s.size();j++){
            for(int k=j+1;k<s.size();k++){
                for(int l=k+1;l<s.size();l++){
                    for(int m=l+1;m<s.size();m++){
                        string cs;
                        cs += s[j];
                        cs += s[k];
                        cs += s[l];
                        cs += s[m];
                        ps.push_back(cs);
                    }
                }
            }
        }
        sort(ps.begin(), ps.end());
        ps.resize(unique(ps.begin(), ps.end()) - ps.begin());
        for(auto x : ps){
            if(!mp.count(x)){
                mp[x] = ++cn;
                str[cn] = x;
            }
            add_edge(i, mp[x], 1);
        }
    }
    snk = cn + 1;
    for(int i=1;i<=n;i++) add_edge(src, i, 1);
    for(int j=n+1;j<=cn;j++) add_edge(j, snk, 1);
    int sz = dinic();
    if(sz == n){    
        for(int i=1;i<=n;i++){
            for(auto k : g[i]){
                if(edgs[k].f == 1){
                    cout << str[edgs[k].v] << "\n";
                }
            }
        }
    }else cout << "-1\n";
}
