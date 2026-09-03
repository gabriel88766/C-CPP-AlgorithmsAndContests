#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3, M = 20;
vector<int> st[4*N]; //insert only
int ans[N];
int rt = 1, anc[N][M], h[N];
vector<int> adj[N];
int q;
void add(int l, int r, int v, int i = 0, int j = q, int p = 1){
    if(i >= l && j <= r){
        st[p].push_back(v);
        return;
    }
    if(i > r || j < l) return;
    int m = (i + j)/2;
    add(l, r, v, i, m, 2*p);
    add(l, r, v, m+1, j, 2*p+1);
}

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

int dist(int a, int b){
    int lc = lca(a, b);
    return h[a] + h[b] - 2 * h[lc];
}

int d1 = -1, d2 = -1, dd = 0;
void dfs_solve(int i = 0, int j = q, int p = 1){
    int ld1 = d1, ld2 = d2, ldd = dd;
    for(auto x : st[p]){
        if(d1 == -1) d1 = x;
        else if(d2 == -1) {d2 = x; dd = dist(d1, d2);}
        else{
            int nd1 = dist(d1, x);
            int nd2 = dist(d2, x);
            if(max(nd1, nd2) > dd){
                if(nd1 >= nd2){
                    d2 = x;
                    dd = nd1;
                }else{
                    d1 = x;
                    dd = nd2;
                }
            }
        }
    }
    if(i == j){
        ans[i] = dd;
    }else{
        int m = (i + j) / 2;
        dfs_solve(i, m, 2 * p);
        dfs_solve(m+1, j, 2*p+1);
    }
    dd = ldd, d1 = ld1, d2 = ld2; //rollback
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build(n);
    cin >> q;
    //queries offline. each insert occur in a interval, add them to seg tree and just do it.
    vector<int> lin(n+1, 0);
    vector<bool> isin(n+1, true);
    vector<tuple<int, int, int>> qrs;
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        if(isin[x]){
            qrs.push_back({x, lin[x], i});
            isin[x] = false;
        }else{
            lin[x] = i+1;
            isin[x] = true;
        }
    }
    for(int i=1;i<=n;i++){
        if(isin[i]) qrs.push_back({i, lin[i], q});
    }
    for(auto [v, l, r] : qrs) add(l, r, v);
    //now just solve it! 
    dfs_solve();
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
}
