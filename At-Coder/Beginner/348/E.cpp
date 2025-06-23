#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N];
ll v[N], sub[N], dp[N];
ll ans = INF_LL;
void dfs1(int u, int p){
    sub[u] = v[u];
    for(auto v : adj[u]){
        if(v != p){
            dfs1(v, u);
            sub[u] += sub[v];
            dp[u] += dp[v] + sub[v];
        }
    }
}

ll cur;
void dfs2(int u, int p){
    ans = min(ans, cur);
    for(auto v : adj[u]){
        if(v != p){
            cur += sub[1] - 2*sub[v];
            dfs2(v, u);
            cur -= sub[1] - 2*sub[v];
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
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    dfs1(1, 0);
    cur = dp[1];
    dfs2(1, 0);
    cout << ans << "\n";
}
