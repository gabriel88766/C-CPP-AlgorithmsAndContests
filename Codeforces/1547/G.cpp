#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 4e5+3;
vector<int> adj[N];
int dfs_low[N], dfs_num[N], cmpnum[N], cntT = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
char visc[N], hl[N];


//graph2
vector<int> adj2[N];
bool hhl[N];
int dp[N];

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

void clear(int n){
    cntT = cntCmp = 0;
    for(int i=1;i<=n;i++){
        adj[i].clear();
        dfs_low[i] = dfs_num[i] = cmpnum[i] = 0;
        cmp[i].clear();
        visc[i] = hl[i] = dp[i] = 0;
        hhl[i] = 0;
        adj2[i].clear();
    }
    curcmp.clear();
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            if(a == b) hl[a] = 1;
            else{
                adj[a].push_back(b);
            }
        }
        for(int i=1;i<=n;i++) if(!visc[i]) tarjan(i);
        for(int i=1;i<=n;i++){
            for(auto v : adj[i]){
                if(cmpnum[i] != cmpnum[v]){
                    adj2[cmpnum[i]].push_back(cmpnum[v]);
                }
            }
            if(hl[i]){
                hhl[cmpnum[i]] = true;
            }
        }

        for(int i=1;i<=cntCmp;i++){
            sort(adj2[i].begin(), adj2[i].end());
            adj2[i].resize(unique(adj2[i].begin(), adj2[i].end()) - adj2[i].begin());
            if(cmp[i].size() > 1) hhl[i] = true;
        }
        dp[cmpnum[1]] = 1;
        for(int i=cntCmp;i>=1;i--){
            if(hhl[i] && dp[i]) dp[i] = INF_INT;
            if(dp[i] >= 2 && dp[i] != INF_INT) dp[i] = 2;
            for(auto v : adj2[i]){
                dp[v] = min(INF_INT, dp[v] + dp[i]);
            }
        }
        for(int i=1;i<=n;i++){
            if(dp[cmpnum[i]] <= 1) cout << dp[cmpnum[i]] << " ";
            else if(dp[cmpnum[i]] != INF_INT) cout << "2 ";
            else cout << "-1 ";
            
        }
        cout << "\n";
        clear(n);
    }
}
