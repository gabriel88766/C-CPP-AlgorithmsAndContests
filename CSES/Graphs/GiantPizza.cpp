//2SAT
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//O(V+E)
const int N = 2e5+3;
vector<int> adj[N];
int dfs_low[N], dfs_num[N], cntT = 0, cntCmp=0;
vector<int> curcmp;
int cmp[N];
char visc[N];

void tarjan(int u){ //SCC
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
            cmp[v] = cntCmp;
            if(v == u) break;
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    // A = 2*i, ~A = 2*i-1
    int n, m;
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        int a, b;
        char c, d;
        cin >> c >> a >> d >> b;
        adj[2*a - (c == '-' ? 0 : 1)].emplace_back(2*b - (d == '+'? 0 : 1)); //~A -> B
        adj[2*b - (d == '-' ? 0 : 1)].emplace_back(2*a - (c == '+'? 0 : 1)); //~B -> A
    }
    for(int i=1;i<=(2*n);i++) if(visc[i] == 0) tarjan(i);
    bool ok = true;
    for(int i=1;i<=(2*n);i+=2){
        if(cmp[i] == cmp[i+1]) ok = false;
    }
    
    if(!ok) cout << "IMPOSSIBLE";
    else{
        for(int i=2;i<=(2*n);i+=2){
            if(cmp[i] < cmp[i-1]) ans[i/2] = '+'; // -  -> + 
            else ans[i/2] = '-';
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
    }
}
  