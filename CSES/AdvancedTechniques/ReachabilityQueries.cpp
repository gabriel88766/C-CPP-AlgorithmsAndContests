#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e4+3;
vector<int> adj[N], adj2[N];
ll bs[N][782];
ll pot[64];
int dfs_low[N], dfs_num[N], cmpNum[N], cntT = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
char visc[N];

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
            cmpNum[v] = cntCmp;
            if(v == u) break;
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    pot[0] = 1;
    for(int i=1;i<64;i++) pot[i] = pot[i-1] * 2;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
    }
    
    for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);

    for(int i=1;i<=n;i++){
        for(auto x : adj[i]){
            if(cmpNum[x] != cmpNum[i]) adj2[cmpNum[i]].emplace_back(cmpNum[x]);
        }
    }

    for(int i=1;i<=cntCmp;i++){
        for(auto x : cmp[i]){
            bs[i][x/64] |= pot[x%64];
        }
    }

    for(int i=1;i<=cntCmp;i++){
        for(auto x : adj2[i]){
            for(int j=0;j<=n/64;j++){
                bs[i][j] |= bs[x][j];
            }
        }
    }

    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        if(cmpNum[a] == cmpNum[b]) cout << "YES\n";
        else{
            if(bs[cmpNum[a]][b/64] & pot[b%64]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}