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
        for(int i=1;i<adj.size();i++) st.update(ord[i], v[i]);
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
        st.update(ord[a], val);
        v[a] = val;
    }
    int query(int a, int b){
        int ans = max(v[a], v[b]);
        while(a != b){ //something like LCA
            if(ord[a] < ord[b]) swap(a, b);
            if(a == beg[a]){
                a = par[a];
                ans = max(ans, v[a]);
            }else{
                int d;
                if(ord[b] <= ord[beg[a]]) d = beg[a];
                else d = b;
                ans = max(ans, st.query(ord[d], ord[a]));
                a = d;
            }
        }
        return ans;
    }
};

//example task
//pathqueries ii

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    HLD h(n+1);
    for(int i=1;i<=n;i++) cin >> h.v[i];
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        h.adj[a].push_back(b);
        h.adj[b].push_back(a);
    }
    h.build();
    for(int i=1;i<=q;i++){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            h.update(a, b);
        }else{
            cout << h.query(a, b) << "\n";
        }
    }
}
