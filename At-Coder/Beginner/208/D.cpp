#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 405;
int adj[N][N];
int dist[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(adj, 63, sizeof(adj));
    memset(dist, 63, sizeof(dist));
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }
    for(int i=1;i<=n;i++) adj[i][i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j] = adj[i][j];
        }
    }
    ll ans = 0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);    
            }
        }
        for(int s=1;s<=n;s++){
            for(int d=1;d<=n;d++){
                if(dist[s][d] != INF_INT) ans += dist[s][d];
                // cout << dist[s][d] << " ";
            }
            // cout << ", ";
        }
        // cout << "\n";
    }
    cout << ans << "\n";
}
