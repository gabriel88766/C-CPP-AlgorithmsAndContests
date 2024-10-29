#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 305;
ll adj[N][N];
ll dist[N][N];
int n;
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
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(adj, 63, sizeof(adj));
    int m;
    cin >> n >> m;
    vector<tuple<int,int,int>> vt;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        vt.push_back({c, a, b});
        adj[a][b] = adj[b][a] = c;
    }
    floyd();
    int ans = 0;
    for(auto [w, a, b] : vt){
        if(dist[a][b] < w) ans++;
        else{
            for(int k=1;k<=n;k++){
                if(k == a || k == b) continue;
                if(dist[a][k] + dist[k][b] == w){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
}
