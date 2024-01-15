#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void bfs(vector<int> &d, vector<vector<int>> &adj, int n, int src){
    for(int i=1;i<=n;i++) d[i] = INF_INT;
    d[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> adj(n+1);
    vector<vector<bool>> road(n+1, vector<bool> (n+1, false));
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        road[a][b] = road[b][a] = true;
    }
    for(int i=1;i<=n;i++) road[i][i] = true;
    vector<int> dt(n+1), ds(n+1);
    bfs(dt, adj, n, t);
    bfs(ds, adj, n, s);
    int d = dt[s];
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(road[i][j]) continue;
            int curd = min(dt[i] + 1 + ds[j], dt[j] + 1 + ds[i]);
            if(curd >= d) ans++;
        }
    }
    cout << ans << "\n";
}
