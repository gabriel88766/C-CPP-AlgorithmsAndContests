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
int n;
ll t;
void floyd(){
    memset(dist, 63, sizeof(dist));
    for(int i=1;i<=n+1;i++) dist[i][i] = 0; 
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        dist[i][j] = min(dist[i][j], adj[i][j]); //caution here
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);    
}


void add_edge(int u, int v, ll w){
    if(w > dist[u][v]) return;
    dist[u][v] = w;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j] = min(dist[i][j], dist[i][u] + dist[u][v] + dist[v][j]);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m;
    cin >> n >> m;
    memset(adj, 63, sizeof(adj));
    for(int i=1;i<=m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = adj[b][a] = min(adj[a][b], c);
    }
    floyd();
    ++n;
    int k;
    cin >> k >> t;
    for(int i=1;i<=k;i++){
        int d;
        cin >> d;
        add_edge(d, n, t);
        add_edge(n, d, 0);
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int tq;
        cin >> tq;
        if(tq == 1){
            int a, b, c;
            cin >> a >> b >> c;
            add_edge(a, b, c);
            add_edge(b, a, c);
        }else if(tq == 2){
            int d;
            cin >> d;
            add_edge(d, n, t);
            add_edge(n, d, 0);
        }else{
            ll ans = 0;
            for(int i=1;i<=n-1;i++){
                for(int j=1;j<=n-1;j++){
                    if(dist[i][j] != INF_LL) ans += dist[i][j];
                }
            }
            cout << ans << "\n";
        }
    }
}
