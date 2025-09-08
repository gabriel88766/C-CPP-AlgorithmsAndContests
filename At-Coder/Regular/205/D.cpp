#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3;
vector<int> adj[N];
int sub[N];
int dp[N];
void dfs(int u){
    sub[u] = 1;
    dp[u] = 0;
    int mx = 0, nd;
    int tt = 0;
    for(auto v : adj[u]){
        dfs(v);
        sub[u] += sub[v];
        mx = max(mx, sub[v] - 2*dp[v]);
        if(mx == sub[v] - 2*dp[v]) nd = v;
    }
  
    int ttx = 0;
    for(auto v : adj[u]){
        if(v != nd) ttx += sub[v];
    }
    if(ttx >= mx){
        for(auto v : adj[u]) dp[u] += sub[v];
        dp[u] /= 2;
    }else{
        dp[u] = dp[nd] + ttx;
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
        for(int i=2;i<=n;i++){
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
        dfs(1);
        cout << dp[1] << "\n";

        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
    }   
}
