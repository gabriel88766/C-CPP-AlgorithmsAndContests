#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 20; 
vector<int> adj[N];
int rt = 1, anc[N][M], h[N];

void dfs(int u, int par){ 
    anc[u][0] = par;
    h[u] = h[par] + 1;
    for(auto x : adj[u]){
        if(x != par){
            dfs(x, u);
        }
    } 
}

void build(int n){
    h[0] = -1;
    dfs(rt, 0);
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
}

int lca(int a, int b){ 
    if(h[a] > h[b]) swap(a, b);
    int diff = h[b] - h[a];
    for(int i = M-1; i>=0;i--) if(diff & (1 << i)) b = anc[b][i];
    if(a == b) return a;
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
    }
    return anc[a][0];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, u, v;
    cin >> n >> u >> v;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build(n);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(adj[i].size() != 1) continue;
        int l1 = lca(i, u);
        int l2 = lca(i, v);
        int d2 = h[i] + h[v] - 2*h[l2];
        int d1 = h[i] + h[u] - 2*h[l1];
        if(d1 < d2){
            //then takahashi may go to this leaf.
            ans = max(ans, d2 - 1);
        }
    }
    cout << ans << "\n";
}
