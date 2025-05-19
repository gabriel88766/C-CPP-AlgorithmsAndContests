#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTree{
    vector<T> st;
    int n;
    SegmentTree(vector<T> &v){
        n = v.size();
        st.resize(2*n);
        build(v);
    }
    SegmentTree(ll sz){
        n = sz;
        st.resize(2*n);
    }
    void build(vector<T> &v){
        for(int i=n;i<2*n;i++) st[i] = v[i-n];
        for(int i=n-1;i>=1;i--) st[i] = op(st[2*i], st[2*i+1]); //merge op
    }
    T query(int l, int r){
        T ans = nullel();
        l += n, r += n;
        while(l <= r){
            int no = l, c = 1;
            while(!(no & 1) && (r-l+1) >= (c << 1)){
                c <<= 1;
                no >>= 1;
            }
            ans = op(ans, st[no]); //merge op
            l += c;
        }
        return ans;
    }
    void update(int l, T val){
        l += n;
        st[l] += val; //assign or increment?
        while(l > 1){
            l >>= 1;
            st[l] = op(st[2*l], st[2*l+1]); //merge op
        }
    }
};

ll op(ll a, ll b){
    return a + b;
}

ll el(){
    return 0LL;
}

const int N = 3e5+3;
int n;
vector<int> adj[N];
pair<int, int> edg[N];
int par[N], ord[N], sub[N];
int cnt = 0;
void dfs(int u, int p){
    ord[u] = ++cnt;
    sub[u] = 1;
    par[u] = p;
    for(auto &v : adj[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<=n-1;i++){
        int a, b;
        cin >> a >> b;
        edg[i] = {a, b};
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    vector<ll> ini(n+1, 1);
    ini[0] = 0;
    SegmentTree<ll, op, el> st(ini);
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t == 1){
            int x, w;
            cin >> x >> w;
            st.update(ord[x], w);
        }else{
            int y;
            cin >> y;
            auto [u, v] = edg[y];
            if(par[v] == u) swap(u, v);
            assert(par[u] == v);
            ll t2 = st.query(ord[u], ord[u] + sub[u] - 1);
            ll t1 = st.query(1, n) - t2;
            cout << abs(t1-t2) << "\n";
        }
    }
}
