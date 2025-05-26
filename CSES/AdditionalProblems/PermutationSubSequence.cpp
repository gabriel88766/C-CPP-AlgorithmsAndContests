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

pair<int, int> op(pair<int, int> a, pair<int, int> b){
    return max(a, b);
}

pair<int, int> el(){
    return {0, 0};
}

int par[200005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1), u(m+1), ord(m+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=m;i++){
        cin >> u[i];
        ord[u[i]] = i;
    }
    SegmentTree<pair<int,int>, op, el> st(m+1);
    for(int i=1;i<=n;i++){
        if(v[i] <= m){
            auto pr = st.query(0, ord[v[i]] - 1);
            int cdp = pr.first + 1;
            par[ord[v[i]]] = pr.second;
            st.update(ord[v[i]], {cdp, ord[v[i]]});
            // cout << v[i] << " " << cdp << "\n";
        }
    }
    vector<int> ans;
    pair<int, int> lst = st.query(1, m);
    int tt = lst.first;
    int rl = lst.second;
    while(tt--){
        ans.push_back(u[rl]);
        rl = par[rl];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto &x : ans) cout << x << " ";
    cout << "\n";
}
