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
    return min(a, b);
}

int el(){
    return 1;
}

const int N = 4e5+3, M = 20;
vector<int> adj[N];
vector<vector<int>> nums(N);
int sub[N], ord[N], invord[N], h[N], anc[M][N], v[N], cu[N];
int node = 0;
void dfs(int u, int p){
    anc[0][u] = p;
    ord[u] = ++node;
    invord[node] = u;
    sub[u] = 1;
    h[u] = h[p] + 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}

void build(int n){
    h[0] = -1;
    for(int j = 1; j < M; j++){
        for(int i = 1; i <= n; i ++){
            anc[j][i] = anc[j-1][anc[j-1][i]];
        }
    }
}

int lca(int a, int b){ 
    if(h[a] > h[b]) swap(a, b);
    int diff = h[b] - h[a];
    for(int i = M-1; i>=0;i--) if(diff & (1 << i)) b = anc[i][b];
    if(a == b) return a;
    for(int i= M-1;i >= 0;i--){
        while(anc[i][a] != anc[i][b]) a = anc[i][a], b = anc[i][b];
    }
    return anc[0][a];
}

void dfs2(int u, int p){
    for(auto v : adj[u]){
        if(v != p){
            dfs2(v, u);
            cu[u] &= cu[v];
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
    for(int i=1;i<=2*n;i++){
        cin >> v[i];
        nums[v[i]].push_back(i);
    }
    for(int i=1;i<2*n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //solve if src is in the final tree
    auto  solve = [&](vector<int> &ans, int src){
        vector<int> aux(2*n+1, 1);
        SegmentTree<int, op, el> st(aux); // 0 means the current position must not be erased

        node = 0;
        h[0] = -1;
        dfs(src, 0);
        build(2*n);
        for(int i=1;i<=2*n;i++) cu[i] = 1;
        for(int i=1;i<=n;i++){
            int a = nums[i][0];
            int b = nums[i][1];
            int lc = lca(a, b);
            cu[lc] = 0;
        }
        dfs2(src, 0);
        vector<bool> af(2*n+1, true);
        set<int> s;
        for(int i=1;i<=2*n;i++) s.insert(i);
        for(int i=2*n;i>=1;i--){
            if(!cu[i]) continue;
            if(st.query(ord[i], ord[i] + sub[i] - 1) == 1){
                //change everything below
                vector<int> rml;
                for(auto it = s.lower_bound(ord[i]);it != s.end() && *it<=ord[i]+sub[i]-1;++it){
                    int j = *it;
                    rml.push_back(j);
                    int vt = invord[j];
                    int ov = invord[j] == nums[v[vt]][0] ? nums[v[vt]][1] : nums[v[vt]][0];
                    st.update(ord[ov], 0);
                    af[vt] = false;
                }
                for(auto x : rml) s.erase(x);
            }
        }
        for(int i=2*n;i>=1;i--){
            if(af[i]) ans.push_back(i);
        }
    };
    vector<int> ans1, ans2;
    solve(ans1, nums[1][0]);
    solve(ans2, nums[1][1]);
    if(ans1 > ans2) ans1.swap(ans2);
    cout << ans1.size() << "\n";
    for(auto x : ans1) cout << x << " ";
    cout << "\n";
    // for(auto x : ans2) cout << x << " ";
    // cout << "\n";
}   
