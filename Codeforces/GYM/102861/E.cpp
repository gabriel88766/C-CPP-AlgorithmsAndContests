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

int op(int a, int b){
    return a + b;
}

int el(){
    return 0;
}

struct Query{
    int l, r, x;
    bool operator< (const Query &q) const {
        return l < q.l;
    }
};

const int N = 1e5+1;
int v[N], ans[N], ord[N], sub[N];
vector<int> adj[N];
int anc[N][20];
vector<int> nv[N];
int cnt = 0;

void dfs(int u){
    sub[u] = 1;
    ord[u] = ++cnt;
    for(auto v : adj[u]){
        dfs(v);
        sub[u] += sub[v];
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    int mv = 0;
    for(int i=1;i<=n;i++){
        int p;
        cin >> v[i] >> p;
        if(i != 1){
            adj[p].push_back(i);
        }
        
         anc[i][0] = p;
        nv[v[i]].push_back(i);
        mv = max(mv, v[i]);
    }
    for(int j=1;j<=19;j++){
        for(int i=1;i<=n;i++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
    vector<Query> vq(m);
    for(int i=0;i<m;i++){
        cin >> vq[i].x >> vq[i].l >> vq[i].r;
    }
    cout.flush();
    sort(vq.begin(), vq.end());
    dfs(1);
    SegmentTree<int, op, el> st(n+2);
    int rem = 1;
    for(int i=0;i<m;i++){
        while(rem < vq[i].l){
            for(int j=0;j<nv[rem].size();j++){
                ans[nv[rem][j]] = st.query(1, ord[nv[rem][j]]);
            }
            rem++;
        }
        int cur = vq[i].x;
        for(int k=19;k>=0;k--){
            while(cur != 1 && v[anc[cur][k]] <= vq[i].r) cur = anc[cur][k];
        }
        st.update(ord[cur], 1);
        st.update(ord[cur] + sub[cur], -1);
    }
    for(int i=rem;i<=mv;i++){
        for(int j=0;j<nv[i].size();j++){
            ans[nv[i][j]] = st.query(1, ord[nv[i][j]]);
        }
    }

    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
