#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 20;
int d[N];
vector<int> adj[N];

int rt = 1, anc[N][M], h[N], md[N][M];

void dfs(int u, int par){ 
    anc[u][0] = par;
    h[u] = h[par] + 1;
    md[u][0] = min(d[u], d[par]);
    for(int i=0;i<adj[u].size();i++){
        auto &x = adj[u][i];
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
            md[i][j] = min(md[i][j-1], md[anc[i][j-1]][j-1]);
        }
    }
}

int lca1(int a, int b){ 
    if(h[a] > h[b]) swap(a, b);
    int ds = h[b] - h[a];
    for(int i = M-1; i>=0;i--) if(ds & (1 << i)) b = anc[b][i];
    if(a == b) return ds;
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i], ds += 2*(1 << i);
    }
    return ds + 2;
}

int lca2(int a, int b){ 
    if(h[a] > h[b]) swap(a, b);
    int diff = h[b] - h[a];
    int mn = min(d[a], d[b]);
    for(int i = M-1; i>=0;i--) if(diff & (1 << i)) {mn = min(mn, md[b][i]); b = anc[b][i];}
    if(a == b) return mn;
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]){
            mn = min({mn, md[a][i], md[b][i]});
            a = anc[a][i], b = anc[b][i];
        }
    }
    mn = min({mn, md[a][0], md[b][0]});
    return mn;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    queue<int> qn;
    memset(d, 63, sizeof(d));
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(x == 1){
            d[i] = 0;
            qn.push(i);
        }
    }
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    while(!qn.empty()){
        auto u = qn.front();
        qn.pop();
        for(auto v : adj[u]){
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                qn.push(v);
            }
        }
    }
    build(n);
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        cout << lca1(a, b) + 2*lca2(a, b) << "\n";
    }
}
