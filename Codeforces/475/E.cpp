//UNSOLVED!!
//LOL!!
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
vector<int> adji[N];
vector<int> adj[N];
set<int> adjT[N];
int Tval[N];
int dfs_low[N], dfs_num[N], cntT = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
int cmpNum[N];
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
            cmpNum[v] = cntCmp;
            if(v == u) break;
        }
    }
}

char vis[N];
map<pair<int,int>, bool> edgv;
void dfs1(int u){
    vis[u] = true;
    for(auto v : adji[u]){
        //test the edge
        int a = u, b = v;
        if(a > b) swap(a, b);
        if(!edgv.count({a, b})){
            edgv[{a, b}] = true;
            adj[u].push_back(v);
        }
        if(!vis[v]){
            dfs1(v);
        }
    }
}
int n;
ll dp[2][N][N], sub[N];
ll bkp[2][N]; 
int sz[N];


void unite(int a, int b, int sza){
    
    for(int i=0;i<=sz[a];i++){
        bkp[0][i] = dp[0][a][i];
        bkp[1][i] = dp[1][a][i];
        dp[0][a][i] = dp[1][a][i] = -INF_INT;
    }
    for(int i=0;i<=sz[a];i++){
        for(int j=0;j<=sz[b];j++){
            dp[0][a][sza] = max(dp[0][a][sza], bkp[1][i] + dp[1][b][j] + j * sza); //
            dp[1][a][sza] = max(dp[1][a][sza], bkp[0][i] + dp[0][b][j] + j * sza); // case 1
            dp[0][a][i+j] = max(dp[0][a][i+j], bkp[0][i] + dp[0][b][j] + j * sza); // case 2
            dp[1][a][i+j] = max(dp[1][a][i+j], bkp[1][i] + dp[1][b][j] + j * sza); // case 5
            dp[0][a][i] = max(dp[0][a][i], bkp[0][i] + dp[1][b][j] + i*j);
            dp[1][a][i] = max(dp[1][a][i], bkp[1][i] + dp[0][b][j] + i*j);  //case 4
            dp[0][a][j+sza] = max(dp[0][a][j+sza], bkp[1][i] + dp[0][b][j] + i*j);
            dp[1][a][j+sza] = max(dp[1][a][j+sza], bkp[0][i] + dp[1][b][j] + i*j); //case3
        }
    }
    sz[a] += sz[b];
}



void dfs(int u, int p = 0){
    dp[0][u][Tval[u]] = dp[1][u][Tval[u]] = 0;
    sz[u] = Tval[u];
    for(auto v: adjT[u]){
        if(v != p){ 
            dfs(v, u);
            unite(u, v, Tval[u]);
        }
    }
    
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<N;i++) for(int j=1;j<N;j++) dp[0][i][j] = dp[1][i][j] = -INF_INT;
    int  m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adji[a].push_back(b);
        adji[b].push_back(a);
    }
    dfs1(1);
    tarjan(1);
    for(int i=1;i<=n;i++){
        Tval[cmpNum[i]] = cmp[cmpNum[i]].size();
        for(auto v : adji[i]){
            if(cmpNum[v] != cmpNum[i]){
                adjT[cmpNum[v]].insert(cmpNum[i]);
                adjT[cmpNum[i]].insert(cmpNum[v]);
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) ans += Tval[i] * Tval[i];
    //now solve for the tree....
    dfs(1);
    ll aux = 0;
    for(int i=0;i<=n;i++) for(int j=0;j<2;j++) aux = max(aux, dp[j][1][i]);
    cout << ans + aux << "\n";
}
