#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e4+3;
vector<int> topo;
bool vis[N];
vector<int> adj[N];
ll bs[50005][782];
ll pot[64];

void dfs_topo(int u){
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs_topo(i);
        }
    }
    topo.push_back(u);
}
void topo_sort(int n){ 
    for(int i=1;i<=n;i++) vis[i] = false;
    for(int i=1;i<=n;i++) if(!vis[i]) dfs_topo(i);  
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    pot[0] = 1;
    for(int i=1;i<64;i++) pot[i] = pot[i-1] * 2;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
    }
    for(int i=1;i<=n;i++){
        bs[i][i/64] |= pot[i%64]; 
    }
    topo_sort(n);
    for(auto x : topo){
        for(auto k : adj[x]){
            for(int i=0;i<=n/64;i++){
                bs[x][i] |= bs[k][i];
            }
        }
    }
    for(int i=1;i<=n;i++){
        ll ans = 0;
        for(int j=0;j<=n/64;j++){
            ans += __builtin_popcountll(bs[i][j]);
        }
        cout << ans << " ";
    }
}
 