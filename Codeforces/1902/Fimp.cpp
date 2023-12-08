#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 20; 
vector<int> adj[N];
int rt = 1, anc[N][M], h[N], v[N];
vector<int> base[N];
vector<int> num[N];
int n;

void dfs(int u, int p){ 
    anc[u][0] = p;
    h[u] = h[p] + 1;
    int aux[20];
    memset(aux, 0, sizeof(aux));
    if(v[u]){
        base[u].push_back(h[u]);
        num[u].push_back(v[u]);
        aux[31-__builtin_clz(v[u])] = v[u];
    }
    
    for(int i=0;i<base[p].size();i++){
        int cur = num[p][i];
        while(cur){
            if(aux[31-__builtin_clz(cur)]){
                cur ^= aux[31-__builtin_clz(cur)];
            }else break;
        }
        if(cur){
            base[u].push_back(base[p][i]);
            num[u].push_back(cur);
            aux[31-__builtin_clz(cur)] = cur;
        }
    }
    
    for(auto x : adj[u]){
        if(x != p){
            dfs(x, u);
        }
    } 
}

void build(){
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
        if(anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
    }
    return anc[a][0];
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> n;
    for(int i=1;i<=n;i++){
        num[i].reserve(21);
        base[i].reserve(21);
    }
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build();
    cin >> q;
    for(int i=0;i<q;i++){
        int x, y, k;
        cin >> x >> y >> k;
        int lc = lca(x, y);
        int aux[20];
        memset(aux, 0, sizeof(aux));
        for(int j=0;j<base[x].size();j++){
            if(base[x][j] >= h[lc]){
                aux[31-__builtin_clz(num[x][j])] = num[x][j];
            }else break;
        }
        for(int j=0;j<base[y].size();j++){
            if(base[y][j] >= h[lc]){
                int cur = num[y][j];
                while(cur){
                    if(aux[31-__builtin_clz(cur)]){
                        cur ^= aux[31-__builtin_clz(cur)];
                    }else break;
                }
                if(cur){
                     aux[31-__builtin_clz(cur)] = cur;
                }
            }else break;
        }
        while(k){
            if(aux[31-__builtin_clz(k)]){
                k ^= aux[31-__builtin_clz(k)];
            }else break;
        }
        if(k) cout << "NO\n";
        else cout << "YES\n";
    }
}
