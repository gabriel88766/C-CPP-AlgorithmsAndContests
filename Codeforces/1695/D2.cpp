#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 200005;
vector<int> adj[N];
int dp[N];
void dfs(int u, int p){
    dp[u] = 0;
    int cnt = 0;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            if(dp[v] == 0) cnt++;
            else dp[u] += dp[v];
        }
    }
    if(cnt > 1) dp[u] += cnt - 1;
}

int cp = 0;
int ans;
void solve(int u, int p){
    if(adj[u].size() == 1 && p != 0){
        ans = min(ans, cp + 1);
        // cout << u << " " << cp + 1 << "\n";
    }
    int sum = 0, ncnt = 0;
    if(u != 1) ncnt += cp == 0;
    sum += cp;
    for(auto v : adj[u]){
        if(v != p){
            sum += dp[v];   
            ncnt += dp[v] == 0;
        }
    }
    int ocp = cp;
    for(auto v : adj[u]){
        if(v != p){
            sum -= dp[v];   
            ncnt -= dp[v] == 0;
            cp = sum; 
            if(ncnt > 1) cp += ncnt - 1;
            solve(v, u);
            sum += dp[v];   
            ncnt += dp[v] == 0;
        }
    }
    cp = ocp;
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
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(n == 1) cout << "0\n";
        else {
            ans = INF_INT;
            dfs(1, 0);
            if(adj[1].size() == 1) ans = dp[1] + 1;
            solve(1, 0);
            cout << ans << "\n";
        }

        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
