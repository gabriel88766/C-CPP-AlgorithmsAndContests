#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int n, k;
vector<int> adj[N];
ll val[N];

ll dp[N][6][2]; //in subtree
void dfs(int u, int p){
    vector<vector<ll>> cdp(7, vector<ll>(3, -INF_LL));
    cdp[0][0] = 0;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            for(int x1=6;x1>=1;x1--){
                for(int x2=x1;x2>=1;x2--){
                    for(int y1=2;y1>=0;y1--){
                        for(int y2=0;y2<=1;y2++){
                            cdp[x1][min(y1 + y2, 2)] = max(cdp[x1][min(y1 + y2, 2)], cdp[x1-x2][y1] + dp[v][x2][y2]);
                        }
                    }
                }
            }
        }
    }
    for(int j=0;j<=5;j++){
        dp[u][j][0] = max({cdp[j][0], cdp[j][1] + val[u], cdp[j+1][2] + val[u]}); //ending paths
        dp[u][j][1] = max({cdp[j][1], cdp[j][2]}) + val[u]; //keeping paths
    }
    for(int j=0;j<=4;j++){
        dp[u][j+1][1] = max(dp[u][j+1][1], cdp[j][0] + val[u]); //starting a new path
    }

}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> val[i];
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    ll ans = 0;
    for(int j=0;j<=k;j++) ans = max({ans, dp[1][j][0], dp[1][j][1]});
    cout << ans << "\n";
}
