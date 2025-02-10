#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int dfs_low[N], dfs_num[N], cmpnum[N], cntT = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
char visc[N];

// for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);
void tarjan(int u){ //SCC, cmp is in inverse topological order 
    dfs_low[u] = dfs_num[u] = ++cntT;
    visc[u] = 1;
    curcmp.emplace_back(u);
    for(auto v : adj[u]){
        if(!dfs_num[v]) tarjan(v);
        if(visc[v] == 1) dfs_low[u] = min(dfs_low[v], dfs_low[u]);
    }
    if(dfs_low[u] == dfs_num[u]){
        ++cntCmp;
        while(true){
            int v = curcmp.back(); curcmp.pop_back(); visc[v] = 2;
            cmp[cntCmp].emplace_back(v);
            cmpnum[v] = cntCmp;
            if(v == u) break;
        }
    }
}

int p[N], sz[N];
bool hg[N];
int ttl[N];
char vis[N];

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
    hg[a] |= hg[b];
    ttl[a] += ttl[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);
    for(int i=1;i<=cntCmp;i++){
        if(cmp[i].size() >= 2) hg[i] = true;
        ttl[i] = cmp[i].size();
    }
    for(int i=1;i<=n;i++){
        for(auto &j : adj[i]){
            if(cmpnum[i] != cmpnum[j]){
                unite(cmpnum[i], cmpnum[j]);
            }
        }
    }
    int ans = 0;
    for(int i=cntCmp;i>=1;i--){
        if(!vis[get(i)]){
            vis[get(i)] = true;
            ans += ttl[get(i)] - 1;
            if(hg[get(i)]) ans++;
        } 
    }
    cout << ans << "\n";
}
