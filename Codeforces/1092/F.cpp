#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
ll wsum[N], c[N], a[N], dp[N];


void dfs(int u, int p = -1){
    wsum[u] = a[u];
    for(auto v: adj[u]){
        if(v != p){
            dfs(v, u);
            c[u] += wsum[v] + c[v];
            wsum[u] += wsum[v];
        }
    }
}

void dfs_2(int u, int p = -1){
    for(auto v: adj[u]){
        if(v != p){
            dp[v] = dp[u] + wsum[1] - 2*wsum[v];
            dfs_2(v, u);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    dp[1] = c[1];
    ll ans = 0;
    dfs_2(1);
    for(int i=1;i<=n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
