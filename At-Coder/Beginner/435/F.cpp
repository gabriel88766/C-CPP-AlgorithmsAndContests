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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1), inv(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        inv[v[i]] = i;
    }
    SegmentTree<int, op, el> st(v);
    function<ll(int, int)> solve = [&](int l, int r){
        int mx = st.query(l, r);
        int pl = inv[mx];
        ll ans = 0;
        if(pl > l){
            ll cur = solve(l, pl - 1);
            int mxl = st.query(l, pl - 1);
            int pll = inv[mxl];
            cur += pl - pll;
            ans = max(ans, cur);
        }
        if(pl < r){
            ll cur = solve(pl + 1, r);
            int mxr = st.query(pl + 1, r);
            int plr = inv[mxr];
            cur += plr - pl;
            ans = max(ans, cur);
        }
        return ans;
    };
    cout << solve(1, n) << "\n";
}
