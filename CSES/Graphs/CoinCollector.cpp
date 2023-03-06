#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//O(V+E)
const int N = 2e5+3;
vector<int> adj[N], adj2[N];
int dfs_low[N], dfs_num[N], cntT = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
char visc[N];
ll c[N], nc[N], dp[N], val[N];

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
            if(v == u) break;
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);
    for(int i=1;i<=cntCmp;i++){
        for(auto x: cmp[i]){
            nc[x] = i;
            val[i] += c[x];
            dp[i] += c[x];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j = 0;j < adj[i].size(); j++){
            if(nc[adj[i][j]] != nc[i]) adj2[nc[i]].push_back(nc[adj[i][j]]);
        }
    }
    for(int i=cntCmp; i>=2; i--){
        for(auto x : adj2[i]){ 
            dp[x] = max(dp[x], dp[i] + val[x]);
        }
    }
    ll ans = 0;
    for(int i=1;i<=cntCmp;i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
}
