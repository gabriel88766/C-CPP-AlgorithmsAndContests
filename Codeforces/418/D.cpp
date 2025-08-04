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
            st[p] += lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
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
    return max(a, b);
}

int el(){
    return 0;
}

const int N = 1e5+3, M = 18; 
vector<int> adj[N];
int rt = 1, anc[N][M], ord[N], sub[N], cnt = 0;
vector<int> h;

void dfs(int u, int par){ 
    ord[u] = ++cnt;
    sub[u] = 1;
    anc[u][0] = par;
    h[u] = h[par] + 1;
    for(auto x : adj[u]){
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

int lift(int a, int k){
    assert(k <= h[a]);
    for(int i=M-1;i>=0;i--){
        if(k & (1 << i)) a = anc[a][i];
    }
    return a;
}

int ans[N];
vector<tuple<int, int, int>> chk[N];
int n;

void dfs2(int u, int p, SegmentTreeLazy<int, op, el> &st){
    for(auto [i, l, r] : chk[u]){
        if(r >= l){
            ans[i] = max(ans[i], st.query(l, r));
            // cout << i << " " << l << " " << r << " " << st.query(l, r) << "\n";
        }
    }
    for(auto v : adj[u]){
        if(v != p){
            st.update(1, n, 1);
            st.update(ord[v], ord[v] + sub[v] - 1, -2);
            dfs2(v, u, st);
            st.update(ord[v], ord[v] + sub[v] - 1, 2);
            st.update(1, n, -1);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m;
    cin >> n;
    h.resize(n+1);
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build(n);
    cin >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        if(h[a] < h[b]) swap(a, b); //that means, the mid is near a
        int lc = lca(a, b);
        int dist = h[a] + h[b] - 2 * h[lc];
        int need_lift = (dist - 1) / 2;
        int y = lift(a, need_lift);
        assert(h[y] > h[lc]);
        chk[a].push_back({i, ord[y], ord[y] + sub[y] - 1});
        chk[b].push_back({i, 1, ord[y] - 1});
        chk[b].push_back({i, ord[y] + sub[y], n});
    }
    vector<int> anh(n+1);
    for(int i=1;i<=n;i++){
        anh[ord[i]] = h[i];
    }
    SegmentTreeLazy<int, op, el> st(anh);
    // cout << st.query(1, n) << " aaa \n";
    dfs2(1, 0, st);
    for(int i=1;i<=m;i++){
        cout << ans[i] << "\n";
    }
}
