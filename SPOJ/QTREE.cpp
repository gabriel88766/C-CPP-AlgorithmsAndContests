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
    SegmentTree(){}
    void resize(int sz){
        n = sz;
        st.resize(2*n);
    }
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

map<pair<int,int>, int> mp;
map<int,int> invmp;
struct HLD{
    vector<int> h;
    vector<bool> hc;
    vector<int> sub;
    vector<int> beg;
    vector<int> ord;
    vector<int> par;
    vector<vector<int>> adj;
    vector<int> v;
    SegmentTree<int, op, el> st;
    int cnt = 0;
    HLD(int n){
        h.resize(n);
        hc.resize(n);
        sub.resize(n);
        beg.resize(n);
        ord.resize(n);
        par.resize(n);
        adj.resize(n);
        v.resize(n);
        st.resize(n);
    }
    void build(){
        dfs(1, 0); //rt = 1 (doesnt matter)
        dfs_hld(1, 0, 1);
        for(int i=2;i<adj.size();i++){
            int p = par[i];
            st.update(ord[i], v[mp[{p, i}]]);
            invmp[mp[{p, i}]] = i;
        }
    }
    void dfs(int u, int p){
        sub[u] = 1;
        par[u] = p;
        for(auto v : adj[u]){
            if(v != p){
                h[v] = h[u] + 1;
                dfs(v, u);
                sub[u] += sub[v];
            }
        }
    }
    //heavy paths order
    void dfs_hld(int u, int p, int bg){
        ord[u] = ++cnt;
        beg[u] = bg;
        int mx = 0, vh = 0;
        for(auto v : adj[u]){
            if(v != p && sub[v] > mx){
                mx = sub[v];
                vh = v;
            }
        }
        if(mx){
            dfs_hld(vh, u, bg);
            for(auto v : adj[u]){
                if(v != vh && v != p) dfs_hld(v, u, v);
            }
        }
    }
    void update(int a, int val){
        a = invmp[a];
        st.update(ord[a], val);
    }
    int query(int a, int b){
        int ans = 0;
        while(a != b){ //something like LCA
            if(ord[a] < ord[b]) swap(a, b);
            if(a == beg[a]){
                ans = max(ans, st.query(ord[a], ord[a]));
                a = par[a];
            }else{
                int d;
                if(ord[b] <= ord[beg[a]]) d = beg[a];
                else d = b;
                ans = max(ans, st.query(ord[d]+1, ord[a]));
                a = d;
            }
        }
        return ans;
    }
};

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
        HLD h(n+1);
        mp.clear();
        invmp.clear();
        for(int i=1;i<n;i++){
            int a, b, c;
            cin >> a >> b >> c;
            h.adj[a].push_back(b);
            h.adj[b].push_back(a);
            mp[{a, b}] = mp[{b, a}] = i;
            h.v[i] = c;
        }
        h.build();
        string s;
        cin >> s;
        while(s != "DONE"){
            int a, b;
            cin >> a >> b;
            if(s == "QUERY"){
                cout << h.query(a, b) << "\n";
            }else{
                //change
                h.update(a, b);
            }
            cin >> s;
        }
    }
}
