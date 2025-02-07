#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int n;
int a[N];
vector<int> adj[N];
int dp[N], ans[N];

void dfs(int u, int p){
    int id = lower_bound(dp, dp + N, a[u]) - dp;
    // cout << id << endl;
    int ov = dp[id];
    dp[id] = a[u];
    int id2 = lower_bound(dp, dp + N, INF_INT) - dp;
    id2 -= 1;
    ans[u] = id2;
    for(auto &v : adj[u]){
        if(v != p) dfs(v, u);
    }
    dp[id] = ov;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //LIS on tree is a dp with rollback :D
    memset(dp, 63, sizeof(dp));
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dp[0] = 0;
    dfs(1, 0);
    for(int i=1;i<=n;i++){
        cout << ans[i] << "\n";
    }
}
