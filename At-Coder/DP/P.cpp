#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N], ch[N];
bool vis[N];
int rt = 1, cnt = 0, po[N], invpo[N];
ll dp[N][2];

void dfs(int u){
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            ch[u].push_back(i);
            dfs(i);
        }
    }
    po[++cnt] = u;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(rt);
    for(int i=1;i<=n;i++){
        int u = po[i];
        if(ch[u].size() == 0) dp[u][0] = dp[u][1] = 1;
        else{
            ll prod1 = 1, prod2 = 1;
            for(auto x : ch[u]){
                prod1 = (prod1 * (dp[x][0] + dp[x][1])) % MOD;
                prod2 = (prod2 * dp[x][0]) % MOD;
            }
            dp[u][0] = prod1, dp[u][1] = prod2;
        }
    }
    cout << (dp[po[n]][1] + dp[po[n]][0]) % MOD;
}
