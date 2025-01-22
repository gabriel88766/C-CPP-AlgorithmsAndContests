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

struct centroid{
    vector<bool> ac;
    vector<int> sub;
    vector<int> par; //parent array after dec.
    vector<vector<int>> tree; //old tree
    vector<vector<int>> adj;
    vector<vector<int>> anc;
    vector<vector<int>> subt;
    vector<int> h;
    int rt; //after dec
    
    void build_distances(){ //LCA
        anc.resize(tree.size());
        h.resize(tree.size());
        h[0] = -1;
        for(int i=0;i<tree.size();i++) anc[i].resize(20);
        function<void(int,int)> dfs = [&](int u, int p){
            anc[u][0] = p;
            h[u] = h[p] + 1;
            for(auto v : tree[u]){
                if(v != p){
                    dfs(v, u);
                }
            }
        };
        dfs(1, 0);
        for(int i=1;i<20;i++){
            for(int j=1;j<tree.size();j++){
                anc[j][i] = anc[anc[j][i-1]][i-1];
            }
        }
    }
    int dist(int a, int b){ //O(log n);
        int ans = 0;
        if(h[a] > h[b]) swap(a, b);
        for(int i=19;i>=0;i--){
            if(h[a] + (1 << i) <= h[b]){
                ans += (1 << i);
                b = anc[b][i];
            }
        }
        if(a == b) return ans;
        for(int i=19;i>=0;i--){
            if(anc[a][i] != anc[b][i]){
                ans += 2 * (1 << i);
                a = anc[a][i];
                b = anc[b][i];
            }
        }
        return ans + 2;
    }
    void dfsT(int u, int p){
        sub[u] = 1;
        for(auto v : tree[u]){
            if(v != p && !ac[v]){
                dfsT(v, u);
                sub[u] += sub[v];
            }
        }
    }
    int find_centroid(int u){
        dfsT(u, 0);
        int sz = sub[u]/2, p = 0;
        while(true){
            int nxt = 0;
            for(auto v: tree[u]){
                if(!ac[v] && sub[v] > sz && v != p){
                    nxt = v;
                }
            }
            if(nxt){
                p = u;
                u = nxt;
            }else break;
        }
        return u;
    }
    void build(){
        subt.resize(tree.size());
        sub.resize(tree.size());
        par.resize(tree.size());
        adj.resize(tree.size());
        ac.assign(tree.size(), false);
        rt = find_centroid(1);
        ac[rt] = true;
        queue<int> q;
        q.push(rt);
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(auto v : tree[u]){
                if(!ac[v]){
                    int t = find_centroid(v);
                    adj[u].push_back(t);
                    par[t] = u;
                    ac[t] = true;
                    q.push(t);
                }
            }
        }
        build_distances();
    }
    void dfs2(int u){
        subt[u].push_back(u);
        for(auto &v : adj[u]){
            dfs2(v);
            for(auto &x : subt[v]) subt[u].push_back(x);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        centroid c;
        int n;
        cin >> n;
        c.tree.resize(n+1);
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            c.tree[a].push_back(b);
            c.tree[b].push_back(a);
        }
        c.build();
        //now c.adj is centroid...
        c.dfs2(c.rt);
        ll ans = 0;
        SegmentTree<ll, op, el> st1(n+1), st2(n+1);
        for(int i=1;i<=n;i++){
            for(auto &v : c.adj[i]){
                vector<int> dst;
                for(auto &x : c.subt[v]) dst.push_back(c.dist(i, x));
                for(auto &x : dst){
                    ans += st1.query(x+1, n) * (2*x-1); //greater than x
                    ans += st2.query(1, x);
                }
                for(auto &x : dst){
                    st1.update(x, 1);
                    st2.update(x, 2*x-1);
                }
            }
            for(auto &v : c.adj[i]){
                for(auto &x : c.subt[v]){
                    st1.update(c.dist(i, x), 0);
                    st2.update(c.dist(i, x), 0);
                }
            }
        }
        cout << ans << "\n";
    }
}