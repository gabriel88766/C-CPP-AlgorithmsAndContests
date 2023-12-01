//Unproven
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e4+3;
vector<int> adj[N];
int indg[N], outdg[N];
int dfs_low[N], dfs_num[N], cntT = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
int nc[N];
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
            nc[v] = cntCmp;
            if(v == u) break;
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);
    if(cntCmp == 1){
        cout << "0\n";
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(auto v : adj[i]){
            if(nc[i] == nc[v]) continue;
            outdg[nc[i]]++;
            indg[nc[v]]++;
        }
    }
    int in = 0, out = 0;
    
    for(int i=1;i<=cntCmp;i++){
        if(indg[i] == 0) in++;
        if(outdg[i] == 0) out++;
    }
    cout << max(in, out) << "\n";
}
