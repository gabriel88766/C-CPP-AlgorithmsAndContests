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

ll op1(ll a, ll b){
    return max(a, b);
}

ll op2(ll a, ll b){
    return min(a, b);
}

ll el1(){
    return -INF_LL;
}

ll el2(){
    return INF_LL;
}

vector<ll> a, b;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    a.resize(n+1);
    b.resize(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    vector<ll> ps(n+1);
    for(int i=1;i<=n;i++){
        ps[i] = ps[i-1] + b[i] - a[i];
    }
    SegmentTree<ll, op1, el1> st1(ps);
    SegmentTree<ll, op2, el2> st2(ps);
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        if(ps[b] != ps[a-1]) cout << "-1\n";
        else{
            ll mx = st1.query(a, b);
            ll mn = st2.query(a, b);
            if(mn < ps[a-1]) cout << "-1\n";
            else cout << mx-mn << "\n";
        }
    }

}
