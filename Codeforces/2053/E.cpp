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
    return a + b;
}

int el(){
    return 0;
}

const int N = 2e5+3;
vector<int> adj[N];
int sub[N], ord[N], par[N];
bool adl[N]; //adjcent to or a leaf;
ll ans;
int cnt = 0;

void clear(int n){
    for(int i=1;i<=n;i++){
        adl[i] = sub[i] = ord[i] = par[i] = 0;
        adj[i].clear();
    }
    cnt = 0;
}
void dfs(int u, int p = 0){
    par[u] = p;
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
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ll lf = 0;
        for(int i=1;i<=n;i++){
            if(adj[i].size() == 1){
                lf++;
                adl[i] = true;
                adl[adj[i][0]] = true;
            }
        }
        ans = lf * (n - lf); //win in round 0;
        //now win in round 2:
        dfs(1, 0);
        vector<int> cur(n+1, 0);
        for(int i=1;i<=n;i++){
            cur[ord[i]] = (adl[i] ? 0 : 1);
        }
        SegmentTree<int, op, el> st(cur);
        for(int i=1;i<=n;i++){
            if(adl[i] && adj[i].size() > 1){
                // cout << i << " ";
                for(auto v : adj[i]){
                    if(adj[v].size() != 1){
                        //v is not leaf, but some v is leaf
                        if(par[v] == i){
                            //then count all - subtree v
                            ans += st.query(1, n) - st.query(ord[v], ord[v] + sub[v] - 1);
                        }else{
                            //then count subtree i
                            ans += st.query(ord[i], ord[i] + sub[i] - 1);
                        }
                    }
                }
            }
        }


        cout << ans << "\n";
        clear(n);
    }
}
