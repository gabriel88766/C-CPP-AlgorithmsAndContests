#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
ll dp[N];
vector<int> topo;
bool vis[N];
vector<int> adj[N], invadj[N];

void dfs_topo(int u){
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs_topo(i);
        }
    }
    topo.push_back(u);
}
void topo_sort(int n){ 
    for(int i=1;i<=n;i++) vis[i] = false;
    for(int i=1;i<=n;i++) if(!vis[i]) dfs_topo(i);
    reverse(topo.begin(), topo.end());   
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n , m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        invadj[b].emplace_back(a);
    }
    topo_sort(1);
    dp[1] = 1;
    for(auto x : topo){
        for(auto y : invadj[x]){
            dp[x] = (dp[x] + dp[y]) % MOD;
        }
    }
    cout << dp[n];
}
