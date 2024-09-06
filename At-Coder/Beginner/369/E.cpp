#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 405;
ll adj[N][N];
vector<pair<int,int>> bdg;
vector<int> db;

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
    bdg.push_back({0, 0});
    db.push_back(0);
    memset(adj, 63, sizeof(adj));
    int m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        ll u, v, t;
        cin >> u >> v >> t;
        bdg.push_back({u, v});
        db.push_back(t);
        adj[u][v] = adj[v][u] = min(adj[u][v], t);
    }
    floyd();
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        vector<int> v(k);
        for(int i=0;i<k;i++) cin >> v[i];
        vector<int> perm;
        for(int i=0;i<k;i++) perm.push_back(i);
        ll ans = INF_LL;
        do{
            for(int j=0;j<(1 << k);j++){
                ll cur = 0;
                int cv = 1;
                for(int b=0;b<k;b++){
                    int nv;
                    if(j & (1 << b)) nv = bdg[v[perm[b]]].second;
                    else nv = bdg[v[perm[b]]].first;
                    cur += dist[cv][nv];
                    cur += db[v[perm[b]]];
                    if(j & (1 << b)) cv = bdg[v[perm[b]]].first;
                    else cv = bdg[v[perm[b]]].second;
                }
                cur += dist[cv][n];
                ans = min(cur, ans);
            }
        }while(next_permutation(perm.begin(), perm.end()));
        cout << ans << "\n";
    }
}
