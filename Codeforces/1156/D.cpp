#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N], adjv[N];
ll ans = 0;

ll dp[N][5]; //0 no edge, 1 all edges 0, 2 all edges 1, 3 sequence 0000...111, 4 sequence 11111.....0000

void dfs(int u, int p = 0){
    dp[u][0] = 1;//only the single vertex
    for(auto v : adj[u]) if(v != p) dfs(v, u);
    for(int i=0;i<adj[u].size();i++){
        auto v = adj[u][i];
        auto t = adjv[u][i];
        if(v != p){
            if(t == 0){
                //0000000
                ans += 2 * (dp[u][0] + dp[u][1]) * (dp[v][0] + dp[v][1]);
                //0000 111 (from v)
                ans += (dp[v][0] + dp[v][1]) * (dp[u][2] + dp[u][4]);
                // 11 00 (from v)
                ans += (dp[v][4] + dp[v][2]) * (dp[u][0] + dp[u][1]);
                dp[u][1] += dp[v][1] + dp[v][0];
                dp[u][4] += dp[v][4] + dp[v][2];
            }else{
                //1111111
                ans += 2 * (dp[u][0] + dp[u][2]) * (dp[v][0] + dp[v][2]);
                //000000 11111 (from u)
                ans += (dp[v][0] + dp[v][2]) * (dp[u][1] + dp[u][3]);
                // 00 11 from v 
                ans += (dp[v][1] + dp[v][3]) * (dp[u][0] + dp[u][2]);
                dp[u][2] += dp[v][2] + dp[v][0];
                dp[u][3] += dp[v][3] + dp[v][1];
            }
        }
    }

}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adjv[u].push_back(w);
        adj[v].push_back(u);
        adjv[v].push_back(w);
    }
    dfs(1);
    cout << ans << "\n";
}
