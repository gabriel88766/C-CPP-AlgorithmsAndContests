#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
vector<int> adj[N];
int dfs_low[N], dfs_num[N], cntT = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
char visc[N];
int n;

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

bool vis[N];
void dfs(int u){
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int  m, s;
    cin >> n >> m >> s;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].emplace_back(b);
    }
    
    dfs(s);
    int ans = 0;
    for(int j=1;j<=n;j++) if(!visc[j]) tarjan(j);
    for(int j=cntCmp; j>=1; j--){
        if(!vis[cmp[j].back()]){
            ans++;
            dfs(cmp[j].back());
        }
    }
    cout << ans;
    
}
