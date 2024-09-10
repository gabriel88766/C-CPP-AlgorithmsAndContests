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
vector<int> adj[N];
int h[N], ord[N], sub[N];
int cnt = 0;
ll ans[N];

void dfs(int u, int p = 0){
    ord[u] = ++cnt;
    h[u] = h[p] + 1;
    sub[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}

struct Query{
    ll val, h, v;
    bool operator< (const Query &q)const {
        return h > q.h;
    }
};
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
    dfs(1);
    int m;
    cin >> m;
    vector<Query> vq(m);
    for(int i=0;i<m;i++){
        cin >> vq[i].v >> vq[i].h >> vq[i].val;
        vq[i].h += h[vq[i].v];
    }
    sort(vq.begin(), vq.end());

    vector<pair<int,int>> vp;
    for(int i=1;i<=n;i++){
        vp.push_back({h[i], i});
    }
    sort(vp.begin(), vp.end(), greater<pair<int,int>>());

    int p0 = 0;
    SegmentTree<ll, op, el> st(n+2);
    for(auto [val, hm, v] : vq){
        while(p0 < n && vp[p0].first > hm){
            ans[vp[p0].second] = st.query(1, ord[vp[p0].second]);
            p0++;
        }
        st.update(ord[v], val);
        st.update(ord[v] + sub[v], -val);
    }
    cout << "\n";
    while(p0 < n){
        ans[vp[p0].second] = st.query(1, ord[vp[p0].second]);
        p0++;
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}
