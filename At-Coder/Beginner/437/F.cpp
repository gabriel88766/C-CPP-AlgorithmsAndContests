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
    return max(a, b);
}

ll el(){
    return -INF_LL;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    SegmentTree<ll, op, el> st0(n+1), st1(n+1), st2(n+1), st3(n+1);
    for(int i=1;i<=n;i++){
        ll x, y;
        cin >> x >> y;
        st0.update(i, -x - y);
        st1.update(i, -x + y);
        st2.update(i, x - y);
        st3.update(i, x + y);
    }
    for(int i=1;i<=q;i++){
        int tq;
        cin >> tq;
        if(tq == 1){
            ll j, x, y;
            cin >> j >> x >> y;
            st0.update(j, -x - y);
            st1.update(j, -x + y);
            st2.update(j, x - y);
            st3.update(j, x + y);
        }else{
            ll l, r, x, y;
            cin >> l >> r >> x >> y;
            ll ans = max({st0.query(l, r) + x + y, st1.query(l, r) + x - y, st2.query(l, r) - x + y, st3.query(l, r) - x - y});
            cout << ans << "\n";
        }
    }
}
