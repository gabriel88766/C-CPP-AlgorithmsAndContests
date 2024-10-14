#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 303;
bool cls[N];
vector<int> qr[N];
tuple<int,int,int> edg[N];


ll adj[M][M];
ll dist[M][M];
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
    int m, q;
    cin >> n >> m >> q;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edg[i] = {a, b, c};
    }
    for(int i=1;i<=q;i++){
        int tq;
        cin >> tq;
        if(tq == 1){
            int x;
            cin >> x;
            qr[i].push_back(1);
            qr[i].push_back(x);
            cls[x] = true;
        }else{
            int u, v;
            cin >> u >> v;
            qr[i].push_back(2);
            qr[i].push_back(u);
            qr[i].push_back(v);
        }
    }
    memset(adj, 63, sizeof(adj));
    for(int i=1;i<=m;i++){
        if(!cls[i]){
            auto [a, b, c] = edg[i];
            adj[a][b] = adj[b][a] = c;
        }
    }
    floyd();
    vector<ll> ans;
    for(int i=q;i>=1;i--){
        int x = qr[i][0];
        if(x == 1){
            auto [a, b, c] = edg[qr[i][1]];
            if(dist[a][b] > c){
                dist[a][b] = dist[b][a] = c;
                for(int j=1;j<=n;j++){
                    for(int k=1;k<=n;k++){
                        dist[j][k] = min(dist[j][k], dist[j][a] + dist[a][b] + dist[b][k]);
                        dist[j][k] = min(dist[j][k], dist[j][b] + dist[b][a] + dist[a][k]);
                    }
                }
            }
        }else{
            int a = qr[i][1];
            int b = qr[i][2];
            ans.push_back(dist[a][b]);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans){
        if(x == INF_LL) cout << "-1\n";
        else cout << x << "\n";
    }
}
