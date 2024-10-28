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

ll op(ll a, ll b){
    return a + b;
}

ll el(){
    return 0LL;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> lc(n+1), val(n+1);
    vector<ll> ans(q+1);
    vector<vector<pair<int,int>>> ql(m+1), qr(m+1);
    vector<vector<tuple<int,int,int>>> qp(m+1);
    vector<int> q3;
    for(int i=1;i<=q;i++){
        int tp;
        cin >> tp;
        if(tp == 1){
            int l, r, c;
            cin >> l >> r >> c;
            ql[l].push_back({i, c});
            if(r != m) qr[r+1].push_back({i, 0});
        }else if(tp == 2){
            int j, x;
            cin >> j >> x;
            lc[j] = i;
            val[j] = x;
        }else{
            int u, v;
            cin >> u >> v;
            q3.push_back(i);
            qp[v].push_back({i, val[u], lc[u]});
        }
    }
    SegmentTree<ll, op, el> st(q+1);
    for(int i=1;i<=m;i++){
        for(auto [j, c] : ql[i]) st.update(j, c);
        for(auto [j, c] : qr[i]) st.update(j, c);
        for(auto [j, val, l] : qp[i]){
            ans[j] = val + st.query(l, j);
        }
    }
    for(auto x : q3) cout << ans[x] << "\n";

}
