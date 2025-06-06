#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 303;
int adj[N][N];
pair<int, int> dist[N][N];
int n, m, L;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dist, 63, sizeof(dist));
    memset(adj, 63, sizeof(adj));
    cin >> n >> m >> L;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = adj[b][a] = c;
    }
    for(int i=1;i<=n;i++){
        dist[i][i] = {0, 0};
        //this is not ideal.. but... let's goo
        //LOL..
        vector<bool> vis(n+1, false);
        while(true){
            int nn = 0;
            for(int j=1;j<=n;j++){
                if(dist[i][j] != make_pair(INF_INT, INF_INT) && dist[i][j] < dist[i][nn] && vis[j] == false) nn = j;
            }
            if(nn == 0) break;
            vis[nn] = true;
            for(int j=1;j<=n;j++){
                if(j == nn) continue;
                if(adj[nn][j] == INF_INT) continue;
                if(dist[i][nn].second + adj[nn][j] <= L) dist[i][j] = min(dist[i][j], make_pair(dist[i][nn].first, dist[i][nn].second + adj[nn][j]));
                else if(adj[nn][j] <= L) dist[i][j] = min(dist[i][j], make_pair(dist[i][nn].first+1, adj[nn][j]));
            }
        }
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        if(dist[a][b] == make_pair(INF_INT, INF_INT)) cout << "-1\n";
        else cout << dist[a][b].first << "\n";
    }
}
