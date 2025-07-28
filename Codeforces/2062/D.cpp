#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
ll l[N], r[N];
ll dp[N], dp2[N];
//dp2 means how many need to be summed in upper tree
void dfs(int u, int p){
    ll mx = 0;
    dp[u] = dp2[u] = 0;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            dp2[u] += dp2[v]; //propagated to all except v
        }
    }
    for(auto v : adj[u]){
        if(v != p){
            mx = max(mx, dp[v] + dp2[u] - dp2[v]);
        }
    }
    l[u] += dp2[u];
    r[u] += dp2[u];
    if(mx <= r[u]) dp[u] = max(l[u], mx);
    else{
        ll sm = 0;
        for(auto v: adj[u]){
            if(v != p){
                if(dp[v] + dp2[u] - dp2[v] > r[u]) sm += dp[v] + dp2[u] - dp2[v] - r[u];
            }
        }
        dp[u] = r[u] + sm;
        dp2[u] += sm;
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
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> l[i] >> r[i];
        }
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }   
        dfs(1, 0);
        cout << dp[1] << "\n";
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
