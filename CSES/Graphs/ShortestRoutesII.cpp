#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//Floyd Warshall O(V^3)
const int N = 505;
ll adj[N][N];
ll dist[N][N];
int n;
void floyd(){
    memset(dist, 63, sizeof(dist));
    for(int i=1;i<=n;i++) dist[i][i] = 0; 
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        dist[i][j] = min(dist[i][j], adj[i][j]);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dist[i][k] < INF_LL && dist[k][j] < INF_LL)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);    
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int m, q;
    cin >> n >> m >> q;  
    memset(adj, 63, sizeof(adj));
    for(int i=0;i<m;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        adj[a][b] = min(adj[a][b], w);
        adj[b][a] = min(adj[b][a], w);
    }
    floyd();
    for(int i=0;i<q;i++){
        int a,b;
        cin >>a >> b;
        cout << (dist[a][b] == INF_LL ? -1 : dist[a][b]) << "\n";
    }
}
 