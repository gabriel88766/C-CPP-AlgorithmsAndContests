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
    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    build(n);
    int l = 1, r = 2;
    int ans = 1;
    cout << ans << " ";
    for(int i=3;i<=n;i++){
        int lca1 = lca(l, i);
        int lca2 = lca(r, i);
        int lc1 = h[l] + h[i] - 2*h[lca1];
        int lc2 = h[r] + h[i] - 2*h[lca2];
        if(lc1 > ans){
            r = i;
            ans = lc1;
        }
        if(lc2 > ans){
            l = i;
            ans = lc2;
        }
        cout << ans << " ";
    }
    cout << "\n";
}   
