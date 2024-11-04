#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
ll dp[N];
ll ans = 0;
void dfs(int u, int p){
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
        }
    }
    if(adj[u].size() == 1) dp[u] = 0;
    else if(adj[u].size() == 2){
        for(auto v : adj[u]){
            if(v != p && adj[v].size() != 2) ans += dp[v];
        }
        dp[u] = 1;
    }else if(adj[u].size() == 3){
        vector<int> aux;
        for(auto v : adj[u]){
            if(v != p){
                aux.push_back(dp[v]);
                dp[u] += dp[v];
            }
        }
        for(int i=0;i<aux.size();i++){
            for(int j=i+1;j<aux.size();j++){
                ans += aux[i] * aux[j];
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
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << "\n";
}
