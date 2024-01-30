#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 505;
ll adj[N][N];
ll dist[N][N];
int n, m;
void floyd(){
    memset(dist, 63, sizeof(dist));
    for(int i=1;i<=n;i++) dist[i][i] = 0; 
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        dist[i][j] = min(dist[i][j], adj[i][j]); //caution here
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dist[i][k] < INF_LL && dist[k][j] < INF_LL)//for negative edge
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);    
}

ll dp[1 << 20][20];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(adj, 63, sizeof(adj));
    memset(dp, 63, sizeof(dp));
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a][b] = w;
    }
    floyd();
    for(int i=0;i<n;i++){
        dp[1 << i][i] = 0;
    }
    for(int i=1;i < (1 << n); i++){
        for(int j=0;j<n;j++){
            if(dp[i][j] == INF_LL) continue;
            for(int k=0;k<n;k++){
                if((1 << k) & i) continue;
                if(dist[j+1][k+1] != INF_LL){
                    dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + dist[j+1][k+1]);
                }
            }
        }
    }
    ll ans = INF_LL;
    for(int i=0;i<n;i++) ans = min(ans, dp[(1 << n) - 1][i]);
    if(ans == INF_LL) cout << "No\n";
    else cout << ans << "\n";
}
