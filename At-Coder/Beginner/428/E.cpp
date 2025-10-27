#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


pair<int, int> op(pair<int, int> a, pair<int, int> b){
    return max(a, b);
}

struct SegmentTreeLazy{
    vector<pair<int, int>> st;
    vector<int> lz;
    int n;
    SegmentTreeLazy(vector<pair<int, int>> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, 0);
        build(v, 0, n-1, 1);
    }
    void build(vector<pair<int, int>>  &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != 0){ //0 can be assigned? change!
            st[p].first += lz[p];
            if(l != r){
                lz[2 * p] += lz[p]; // += increment = update
                lz[2 * p + 1] += lz[p];
            } 
            lz[p] = 0;
        }
    }

    pair<int, int> query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return make_pair(0, 0);
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    pair<int, int> query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, int val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, int val){
        update(i, j, val, 0, n-1, 1);
    }
};

const int N = 5e5+3;
int pos[N], sub[N], h[N], invpos[N], ans[N];
int cnt = 0;
vector<int> adj[N];
void dfs1(int u, int p){
    h[u] = h[p] + 1;
    pos[u] = ++cnt;
    invpos[cnt] = u;
    sub[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs1(v, u);
            sub[u] += sub[v];
        }
    }
}

void solve(int u, int p, SegmentTreeLazy &st){
    auto cans = st.query(0, st.n - 1);
    ans[u] = cans.second;
    for(auto v : adj[u]){
        if(v != p){
            st.update(0, st.n - 1, 1);
            st.update(pos[v], pos[v] + sub[v] - 1, -2);
            solve(v, u, st);
            st.update(pos[v], pos[v] + sub[v] - 1, 2);
            st.update(0, st.n - 1, -1);
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
    h[0] = -1;
    dfs1(1, 0);
    vector<pair<int, int>> sv;
    sv.push_back({-INF_INT, 0});
    for(int i=1;i<=n;i++){
        sv.push_back({h[invpos[i]], invpos[i]});
    }
    SegmentTreeLazy st(sv);
    solve(1, 0, st);
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
}
