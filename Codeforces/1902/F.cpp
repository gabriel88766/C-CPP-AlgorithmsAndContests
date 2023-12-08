#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 20;
vector<int> adj[N];
int anc[N][M], v[N], h[N];
int mult[N][M][M];
int n, rt = 1;


void insert(int *ans, int cur){
    while(cur){
        if(ans[31-__builtin_clz(cur)]){
            cur ^= ans[31-__builtin_clz(cur)];
        }else{
            ans[31-__builtin_clz(cur)] = cur;
            break;
        }
    }
}

void dfs(int u, int par){ 
    anc[u][0] = par;
    insert(mult[u][0], v[par]);
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
            for(int k=M-1;k>=0;k--){
                insert(mult[i][j], mult[anc[i][j-1]][j-1][k]);    
                insert(mult[i][j], mult[i][j-1][k]); 
            }
        }
    }
}

void lca(int *ans, int a, int b){ 
    if(h[a] > h[b]) swap(a, b);
    int diff = h[b] - h[a];
    for(int i = M-1; i>=0;i--){
         if(diff & (1 << i)){
            for(int k=M-1;k>=0;k--){
                insert(ans, mult[b][i][k]);
            }
            b = anc[b][i];
        }
    }
    if(a == b){
        insert(ans, v[a]);
        return;
    }
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]){
            for(int k=M-1;k>=0;k--){
                insert(ans, mult[b][i][k]);
                insert(ans, mult[a][i][k]);
            }
            a = anc[a][i], b = anc[b][i];
        }
    }
    for(int k=M-1;k>=0;k--){
        insert(ans, mult[a][0][k]);
    }
    return;
}
int ans[20];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build(n);
    cin >> q;
    for(int i=0;i<q;i++){
        int x, y, k;
        cin >> x >> y >> k;
        memset(ans, 0, sizeof(ans));
        lca(ans, x, y);
        insert(ans, v[x]);
        insert(ans, v[y]);
        while(k){
            if(ans[31-__builtin_clz(k)]){
                k ^= ans[31-__builtin_clz(k)];
            }else break;
        }
        if(!k) cout << "YES\n";
        else cout << "NO\n";
    }

}
