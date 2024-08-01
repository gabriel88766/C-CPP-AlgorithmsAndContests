#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll a[N], dp[N];
vector<int> adj[N];

void dfs(int u){
    if(adj[u].size() == 0){
        dp[u] = a[u];
        return;
    }
    ll mn = INF_LL;
    for(auto v : adj[u]){
        dfs(v);
        mn = min(mn, dp[v]);
    }
    if(u != 1){
        if(a[u] < mn)  dp[u] = (a[u] + mn)/2;
        else dp[u] = mn;
    }else dp[u] = a[u] + mn;
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
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=2;i<=n;i++){
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
        
        dfs(1);
        cout << dp[1] << "\n";

        for(int i=1;i<=n;i++){
            adj[i].clear();
            dp[i] = a[i] = 0;
        }
    }
}
