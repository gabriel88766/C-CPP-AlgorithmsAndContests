#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
vector<int> adj[N];
int d1[N], dn[N];

void bfs(int *dist, int src){
    
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
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
    memset(d1, 63, sizeof(d1));
    memset(dn, 63, sizeof(dn));
    int n, m;
    cin >> n >> m;
    vector<int> vv;
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        if(u != 0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }else{
            vv.push_back(v);
        }
    }
    bfs(d1, 1);
    bfs(dn, n);
    int bd = d1[n];
    int cn = 0, c1 = 0;
    bool hn = false, h1 = false;
    for(auto x : vv){
        if(d1[c1] > d1[x]) c1 = x;
        if(dn[cn] > dn[x]) cn = x;
        if(x == 1) h1 = true;
        if(x == n) hn = true;
    }
    if(h1 && hn) bd = min(bd, 2);
    for(int i=1;i<=n;i++){
        int bc = bd;
        bc = min(bc, d1[i] + dn[cn] + 1);
        bc = min(bc, d1[c1] + dn[i] + 1);
        if(bc == INF_INT) cout << "-1 ";
        else cout << bc << " ";
    }
    cout << "\n";
}
