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
        st[l] = val; //assign or increment?
        while(l > 1){
            l >>= 1;
            st[l] = op(st[2*l], st[2*l+1]); //merge op
        }
    }
};

int op(int a, int b){
    return max(a, b);
}

int el(){
    return 0;
}

const int N = 4e5+3;
int val[N];
vector<int> adj[N];
int ord[N], sub[N], cnt;

void dfs(int u, int p){
    ord[u] = ++cnt;
    sub[u] = 1;
    for(auto v : adj[u]){
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++) cin >> val[i];
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >>  b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cnt = 0;
        dfs(1, 0);
        SegmentTree<int, op, el> st(n+1);
        for(int i=1;i<=n;i++){
            assert(ord[i] <= n && ord[i] > 0);
            st.update(ord[i], val[i]);
        }
        int ans = 0;
        vector<pair<int, int>> vp;
        for(int i=1;i<=n;i++) vp.push_back({val[i], i});
        sort(vp.begin(), vp.end(), greater<pair<int,int>>());
        for(auto [w, j] : vp){
            int mx = 0;
            if(ord[j] > 1) mx = max(mx, st.query(1, ord[j] - 1));
            if(ord[j] + sub[j] <= n) mx = max(mx, st.query(ord[j] + sub[j], n));
            if(mx > w){
                ans = j;
                break;
            }
        }
        cout << ans << "\n";

        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
