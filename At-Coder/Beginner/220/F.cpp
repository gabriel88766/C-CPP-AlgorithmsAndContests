#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int sub[N];
ll dp[N];
void dfs1(int u, int p = 0){
    sub[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs1(v, u);
            sub[u] += sub[v];
            dp[u] += sub[v] + dp[v];
        }
    }
}
int n;

void dfs2(int u, int p = 0){
    for(auto v : adj[u]){
        if(v != p){
            dp[v] = dp[u] - 2 * sub[v] + n;
            dfs2(v, u);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1);
    dfs2(1);
    for(int i=1;i<=n;i++){
        cout << dp[i] << "\n";
    }
}
