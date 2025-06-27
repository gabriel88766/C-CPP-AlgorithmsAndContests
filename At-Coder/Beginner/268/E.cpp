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

const int N = 2e5+3;
ll ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v;
    SegmentTree<ll, op, el> st(n), st2(n);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        int zr;
        if(x >= i) zr = x - i;
        else zr = n - (i - x);
        // v.push_back(zr);
        st.update(zr, zr);
        st2.update(zr, 1);
    }
    // sort(v.begin(), v.end());
    ll ans = INF_LL;
    for(int i=0;i<n;i++){
        ll cur = 0;
        if(i >= n/2){
            cur += st2.query(i - n/2, i - 1) * i - st.query(i - n/2, i - 1);
            cur += st.query(i, n-1) - i * st2.query(i, n-1);
            if(i > n/2) cur += (n - i) * st2.query(0, i-n/2 - 1) + st.query(0, i-n/2 - 1);// n - (i - x)
        }else{
            cur += st.query(i + 1, i + n/2) - i * st2.query(i + 1, i + n/2);
            cur += st2.query(0, i) * i - st.query(0, i);
            if(i + n/2 < n) cur += (n + i) * st2.query(i+n/2+1, n-1) - st.query(i+n/2+1, n-1); //n - (x - i)
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";

}
