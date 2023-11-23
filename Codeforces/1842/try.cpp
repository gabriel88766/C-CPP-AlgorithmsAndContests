#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3, M = 20; 
vector<int> adj[N];
int rt = 1, anc[N][M], h[N];
int qt[51][N][M];

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
    for(int k=1;k<=50;k++){
        for(int j = 1; j < M; j++){
            for(int i = 1; i <= n; i ++){
                qt[k][i][j] = qt[k][i][j-1] + qt[k][anc[i][j-1]][j-1];
            }
        }
    }
    
}

int lca(int a, int b, int k){ 
    int ans = 0;
    if(h[a] > h[b]) swap(a, b);
    int diff = h[b] - h[a];
    for(int i = M-1; i>=0;i--) if(diff & (1 << i)){
         ans += qt[k][b][i];
         b = anc[b][i];
    }
    if(a == b) return ans + qt[k][a][0];
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]){
            ans += qt[k][a][i] + qt[k][b][i];
             a = anc[a][i], b = anc[b][i];
        }
    }
    ans += qt[k][a][1] + qt[k][b][0];
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int w;
        cin >> w;
        assert(w <= 50);
        qt[w][i][0] = 1;
    }
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build(n);
    cout.flush();
    for(int i=0;i<q;i++){
        int k, a, b;
        cin >> k >> a >> b;
        int cur = 1;
        while(lca(a, b, cur) < k){
            k -= lca(a, b, cur);
            cur++;
            assert(cur <= 50);
        }
        cout << cur << "\n";
    }


}
