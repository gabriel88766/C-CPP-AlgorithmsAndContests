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

    ll query(int i, int j, int l, int r, int p){
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


const int N = 2e5+3, M = 20; 
vector<int> adj[N];
int rt = 1, anc[N][M], h[N], sub[N], ord[N];
int cnt = 0;
void dfs(int u, int par){ 
    ord[u] = ++cnt;
    anc[u][0] = par;
    h[u] = h[par] + 1;
    sub[u] = 1;
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

int lift(int a, int d){
    for(int i=M-1;i>=0;i--){
        if(d & (1 << i)) a = anc[a][i];
    }
    if(a == 0) a = 1;
    return a;
}

vector<pair<int,int>> qr[N];
int ans[N];
SegmentTreeLazy<int, op, el> st(1);
int n;
void dfs2(int u, int p = 0){
    for(auto [j, k] : qr[u]){
        int v = lift(u, k);
        ans[j] = st.query(ord[v], ord[v]+sub[v]-1);
    }
    for(auto v : adj[u]){
        if(v != p){
            st.update(ord[v], ord[v] + sub[v] - 1, -1);
            if(1 <= ord[v] - 1) st.update(1, ord[v]-1, 1);
            if(ord[v] + sub[v] <= n) st.update(ord[v] + sub[v], n, 1);
            dfs2(v, u);
            st.update(ord[v], ord[v] + sub[v] - 1, 1);
            if(1 <= ord[v] - 1) st.update(1, ord[v]-1, -1);
            if(ord[v] + sub[v] <= n) st.update(ord[v] + sub[v], n, -1);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        build(n);
        st = SegmentTreeLazy<int, op, el>(n+1);
        for(int i=1;i<=n;i++) st.update(ord[i], ord[i], h[i]);
        int q;
        cin >> q;
        for(int i=0;i<q;i++){
            int u, k;
            cin >> u >> k;
            qr[u].push_back({i, k});
        }
        dfs2(1);
        for(int i=0;i<q;i++) cout << ans[i] << " ";
        cout << "\n";
        for(int i=1;i<=n;i++){
            adj[i].clear();
            qr[i].clear();
        }
        cnt = 0;
    }
}
