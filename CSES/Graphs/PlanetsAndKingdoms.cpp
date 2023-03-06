#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int dfs_low[N], dfs_num[N], cnt = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
char visc[N];

void tarjan(int u){ //SCC
    dfs_low[u] = dfs_num[u] = ++cnt;
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

int ans[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].emplace_back(b);
    }
    for(int i=1;i<=n;i++) if(!visc[i]) tarjan(i);
    for(int i=1;i<=cntCmp;i++) for(int j=0;j<cmp[i].size(); ++j) ans[cmp[i][j]] = i;
    cout << cntCmp << "\n";
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}
