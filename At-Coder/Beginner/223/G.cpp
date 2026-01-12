#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int dp[N][2];
int par[2];
bool ok[N];
int mx = 0;
vector<int> adj[N];
void dfs1(int u, int p){
    int cmx = 0;
    int sum = 0;
    for(auto v : adj[u]){
        if(v != p){
            dfs1(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            sum += max(dp[v][0], dp[v][1]);
        }
    }
    for(auto v : adj[u]){
        if(v != p){
            sum -= max(dp[v][0], dp[v][1]);
            cmx = max(cmx, sum + 1 + dp[v][0]);
            sum += max(dp[v][0], dp[v][1]);
        }
    }
    dp[u][1] = cmx;
}
int ans = 0;
void dfs2(int u, int p){
    int pdg = 0;
    int cs = max(par[0], par[1]);
    if(par[0] == par[1] && u != 1) pdg++;
    for(auto v : adj[u]){
        if(v != p){
            cs += max(dp[v][0], dp[v][1]);
            if(dp[v][0] == dp[v][1]) pdg++;
        }
    }
    if(cs == mx){ 
        ans++;
    }

    for(auto v : adj[u]){
        if(v != p){
            int op[2];
            op[0] = par[0], op[1] = par[1];
            if(dp[v][0] == dp[v][1]) pdg--;
            cs -= max(dp[v][0], dp[v][1]);

            if(pdg){
                par[1] = cs + 1;
            }else{
                par[1] = cs;
            }
            par[0] = cs;
            dfs2(v, u);
            
            cs += max(dp[v][0], dp[v][1]);
            if(dp[v][0] == dp[v][1]) pdg++;
            par[0] = op[0], par[1] = op[1];
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
    dfs1(1, 0);
    mx = max(dp[1][0], dp[1][1]);
    dfs2(1, 0);
    cout << ans << "\n";
}
