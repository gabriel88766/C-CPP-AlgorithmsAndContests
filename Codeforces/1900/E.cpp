#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
vector<int> adj[N], adjc[N];
int dfs_low[N], dfs_num[N], cntT = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
int inC[N];
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
            inC[v] = cntCmp;
            if(v == u) break;
        }
    }
}
ll val[N];
pair<ll,ll> dp[N];
int vis[N];

void dfs(int u){
    vis[u] = true;
    ll tts = 0;
    ll qt = cmp[u].size();
    for(auto v : cmp[u]){
        tts += val[v];
    }
    if(adjc[u].size() == 0){
        dp[u] = {qt, tts};
    }else{
        ll maxsz = 0, minv = INF_LL;
        for(auto v : adjc[u]){
            if(!vis[v]) dfs(v);
            if(dp[v].first > maxsz){
                maxsz = dp[v].first;
                minv = dp[v].second;
            }else if(dp[v].first == maxsz){
                minv = min(minv, dp[v].second);
            }
        }
        dp[u] = {qt + maxsz, minv + tts};
    }
    

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
        for(int i=1;i<=n;i++) cin >> val[i];
        map<pair<int,int>, bool> mp; 
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            if(a != b && !mp[{a,b}]) adj[a].push_back(b);
            mp[{a,b}] = true;
        }
        for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);
        mp.clear();
        for(int i=1;i<=n;i++){
            for(auto v : adj[i]){
                if(inC[v] != inC[i] && !mp[{inC[i], inC[v]}]){
                    adjc[inC[i]].push_back(inC[v]);
                    mp[{inC[i], inC[v]}] = true;
                }
            }
        }
        for(int i=cntCmp; i >= 1; i--){
            if(!vis[i]){
                dfs(i);
            }
        }
        ll maxsz = 0, minv = INF_LL;
        for(int i=cntCmp; i>=1; i--){
            if(dp[i].first > maxsz){
                maxsz = dp[i].first;
                minv = dp[i].second;
            }else if(dp[i].first == maxsz){
                minv = min(minv, dp[i].second);
            }
        }
        cout << maxsz << " " << minv << "\n";
        for(int i=1;i<=n;i++){
            adj[i].clear();
            dfs_low[i] = dfs_num[i] = visc[i] = inC[i] = val[i] = 0;
            cmp[i].clear();
            curcmp.clear();
            adjc[i].clear();
            dp[i] = {0, 0};
            vis[i] = 0;
        }
        cntT = 0, cntCmp=0;
    }
}
