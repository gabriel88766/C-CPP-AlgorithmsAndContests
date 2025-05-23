#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

using namespace __gnu_pbds; //required 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 


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
    return 0LL;
}
const int N = 2e5+3;
int ans[N], aux[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    auto xv = v;
    sort(xv.begin(), xv.end());
    xv.resize(unique(xv.begin(), xv.end()) - xv.begin());
    for(int i=0;i<n;i++){
        v[i] = lower_bound(xv.begin(), xv.end(), v[i]) - xv.begin();
    }
    SegmentTree<int, op, el> st(xv.size());
    int mx = xv.size() - 1;
    ordered_set<int> sx;
    for(int i=0;i<n;i++) sx.insert(i);
    for(int i=0;i<n;i++){
        int xx = st.query(v[i] + 1, mx);
        xx = min(xx, k);
        aux[i] = xx;
        st.update(v[i], 1);
    }
    for(int i=n-1;i>=0;i--){
        int xx = min(aux[i], k);
        int ord = sx.size() - 1 - xx;
        assert(xx < sx.size());
        auto ix = sx.find_by_order(ord);
        ans[*ix] = v[i];
        sx.erase(ix);
    }
    for(int i=0;i<n;i++){
        cout << xv[ans[i]] << " ";
    }
    cout << "\n";
}
