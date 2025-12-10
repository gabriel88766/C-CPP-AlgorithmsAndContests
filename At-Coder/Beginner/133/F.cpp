#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTreeLazy{
    vector<T> st, lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, 0);
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, 0);
        lz.assign(4*n, 0);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != 0){ //0 can be assigned? change!
            st[p] += (r - l + 1) * lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
            if(l != r){
                lz[2 * p] += lz[p]; // += increment = update
                lz[2 * p + 1] += lz[p];
            } 
            lz[p] = 0;
        }
    }

    T query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return nullel();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, T val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, T val){
        update(i, j, val, 0, n-1, 1);
    }
};

int op(int a, int b){
    return a + b;
}

int el(){
    return 0;
}


const int N = 2e5+3, M = 20; 
vector<pair<int, int>> adj[N];
int rt = 1, anc[N][M], h[N];
int sub[N], ord[N], cc = 0;

void dfs(int u, int par){ 
    anc[u][0] = par;
    h[u] = h[par] + 1;
    sub[u] = 1;
    ord[u] = ++cc;
    for(auto [x, d] : adj[u]){
        if(x != par){
            dfs(x, u);
            sub[u] += sub[x];
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

int ans[N];
vector<tuple<int, int, int>> edg[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
        edg[c].push_back({a, b, d});
    }
    build(n);
    SegmentTreeLazy<int, op, el> st1(n+1), st2(n+1);
    for(int u=1;u<=n;u++){
        for(auto [v, d] : adj[u]){
            if(ord[u] < ord[v]){
                //then u is parent //dv ?? 
                st1.update(ord[v], ord[v] + sub[v] - 1, d);
            }
        }
    }
    vector<tuple<int, int, int, int, int>> qr;
    for(int i=1;i<=q;i++){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        qr.push_back({x, y, u, v, i});
    }
    sort(qr.begin(), qr.end());
    vector<int> ans(q+1);
    int px = 0;
    for(int i=1;i<=n;i++){
        for(auto [a, b, d] : edg[i]){
            if(ord[a] > ord[b]) swap(a, b);
            st1.update(ord[b], ord[b] + sub[b] - 1, -d);
            st2.update(ord[b], ord[b] + sub[b] - 1, 1);
        }
        while(px < qr.size() && get<0>(qr[px]) == i){
            auto [x, y, u, v, j] = qr[px];
            int lc = lca(u, v);
            ans[j] += st1.query(ord[u], ord[u]) + st1.query(ord[v], ord[v]) - st1.query(ord[lc], ord[lc]) * 2;
            ans[j] += (st2.query(ord[u], ord[u]) + st2.query(ord[v], ord[v]) - st2.query(ord[lc], ord[lc]) * 2) * y;
            px++;
        }
        for(auto [a, b, d] : edg[i]){
            if(ord[a] > ord[b]) swap(a, b);
            st1.update(ord[b], ord[b] + sub[b] - 1, d);
            st2.update(ord[b], ord[b] + sub[b] - 1, -1);
        }
    }
    for(int i=1;i<=q;i++){
        cout << ans[i] << "\n";
    }
}
