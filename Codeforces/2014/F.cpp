#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
ll dp[N][2], v[N];
ll c;
void dfs(int u, int p = 0){
    dp[u][0] = 0;
    dp[u][1] = v[u];
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            dp[u][1] += max(dp[v][0], dp[v][1] - 2*c);
            dp[u][0] += max(dp[v][0], dp[v][1]);
        }
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
        int n;
        cin >> n >> c;
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0);
        cout << max(dp[1][0], dp[1][1]) << "\n";
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
