#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTreeLazy{
    vector<T> st, lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size() - 1;
        st.resize(4*n);
        lz.assign(4*n, 0);
        build(v, 1, n, 1);
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
        return query(i, j, 1, n, 1);
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
        update(i, j, val, 1, n, 1);
    }
};

int opmn(int a, int b){
    return min(a, b);
}

int elmn(){
    return N;
}

int opmx(int a, int b){
    return max(a, b);
}

int elmx(){
    return 0;
}

SegmentTreeLazy<int, opmn, elmn> stmn(1);
SegmentTreeLazy<int, opmx, elmx> stmx(1);
vector<int> adj[N];
vector<pair<int,int>> qr[N];
int sub[N], ord[N], h[N], ans[N], invord[N];
int cn = 0;

void dfs1(int u, int p){
    h[u] = h[p] + 1;
    ord[u] = ++cn;
    invord[cn] = u;
    sub[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs1(v, u);
            sub[u] += sub[v];
        }
    }
}

int find(int l, int r, int p, int k){
    if(l == r) return l;
    int m = (l + r)/2;
    stmn.push(l, m, 2*p);
    stmx.push(l, m, 2*p);
    if(stmn.st[2*p] <= k && stmx.st[2*p] >= k) return find(l, m, 2*p, k);
    else{
        stmn.push(m+1, r, 2*p+1);
        stmx.push(m+1, r, 2*p+1);
        return find(m+1, r, 2*p+1, k);
    }
}

void solve(int u, int p){
    for(auto [k, j] : qr[u]){
        if(stmn.query(1, cn) <= k && stmx.query(1, cn) >= k){
            ans[j] = invord[find(1, cn, 1, k)];
        }else ans[j] = -1;
    }
    for(auto v : adj[u]){
        if(v != p){
            stmn.update(1, cn, 1);
            stmn.update(ord[v], ord[v] + sub[v] - 1, -2);
            stmx.update(1, cn, 1);
            stmx.update(ord[v], ord[v] + sub[v] - 1, -2);
            solve(v, u);
            stmn.update(1, cn, -1);
            stmn.update(ord[v], ord[v] + sub[v] - 1, 2);
            stmx.update(1, cn, -1);
            stmx.update(ord[v], ord[v] + sub[v] - 1, 2);
        }
    }
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
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int u, k;
        cin >> u >> k;
        qr[u].push_back({k, i});
    }
    h[0] = -1;
    dfs1(1, 0);
    vector<int> ah(n+1);
    for(int i=1;i<=n;i++) ah[ord[i]] = h[i];
    stmn = SegmentTreeLazy<int, opmn, elmn>(ah);
    stmx = SegmentTreeLazy<int, opmx, elmx>(ah);
    solve(1, 0);
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
}
