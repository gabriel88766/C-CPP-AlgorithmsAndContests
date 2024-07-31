#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1003; //2*Nmax + 5
vector<int> adj[N];
int dfs_low[N], dfs_num[N], cntT = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
int cmpnum[N];
char visc[N];

// for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);
void tarjan(int u){ //SCC, cmp is in inverse topological order 
    dfs_low[u] = dfs_num[u] = ++cntT;
    visc[u] = 1;
    curcmp.emplace_back(u);
    for(auto v : adj[u]){
        if(!dfs_num[v]) tarjan(v);
        if(visc[v] == 1) dfs_low[u] = min(dfs_low[v], dfs_low[u]);
    }
    if(dfs_low[u] == dfs_num[u]){
        ++cntCmp;
        while(true){
            int v = curcmp.back(); curcmp.pop_back(); visc[v] = 2;
            cmp[cntCmp].emplace_back(v);
            cmpnum[v] = cntCmp;
            if(v == u) break;
        }
    }
}

//2n = a, 2n+1 = ~a, n >= 1 or 0, your choice. 
bool sat2(int n){
    bool ok = true;
    for(int i=2;i<=2*n+1;i++) if(visc[i] == 0) tarjan(i);
    for(int i=1;i<=n;i++){
        if(cmpnum[2*i] == cmpnum[2*i+1]) ok = false;
    }
    return ok;
}

//a->b
void add_edge(int a, int b){
    adj[a].push_back(b);
}

void add_or(int a, int b){
    add_edge(a^1, b);
    add_edge(b^1, a);
}

void clear(int n){
    cntT = cntCmp = 0;
    curcmp.clear();
    for(int i=0;i<=n;i++){
        dfs_num[2*i] = dfs_num[2*i+1] = dfs_low[2*i] = dfs_low[2*i+1] = visc[2*i] = visc[2*i+1] = 0;
        cmp[2*i].clear();
        cmp[2*i+1].clear();
        adj[2*i].clear();
        adj[2*i+1].clear();
    }
}

//specific 1971H
int conv(int n){
    if(n < 0) return 2*abs(n) + 1;
    else return 2*n;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> v(3, vector<int>(n));
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                cin >> v[i][j];
            }
        }
        for(int i=0;i<n;i++){
            add_edge(conv(-v[0][i]), conv(v[1][i]));
            add_edge(conv(-v[0][i]), conv(v[2][i]));
            add_edge(conv(-v[1][i]), conv(v[0][i]));
            add_edge(conv(-v[1][i]), conv(v[2][i]));
            add_edge(conv(-v[2][i]), conv(v[0][i]));
            add_edge(conv(-v[2][i]), conv(v[1][i]));
        }
        if(sat2(n)) cout << "YES\n";
        else cout << "NO\n";

        clear(n);
    }
}
