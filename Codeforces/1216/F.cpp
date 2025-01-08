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

ll opmn(ll a, ll b){
    return min(a, b);
}

ll elmn(){
    return INF_LL;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = " " + s;
    vector<ll> vx(n+1, INF_LL);
    vx[0] = 0;
    SegmentTree<ll, opmn, elmn> dp1(vx);//dp1 is the minimum value for valid up to i+k and i being chose
    SegmentTree<ll, opmn, elmn> dp2(vx);//dp2 is the minimum value for all picked up to i
    dp2.update(1, 1);
    if(s[1] == '1') dp1.update(1, 1);
    for(int i=2;i<=n;i++){
        if(s[i] == '1'){
            dp1.update(i, i + dp2.query(max(i-k-1, 0), i-1));
        } 
        dp2.update(i, dp1.query(max(i-k, 1), i));
        if(dp2.query(i, i) > i + dp2.query(i-1, i-1)){
            dp2.update(i, i + dp2.query(i-1, i-1));
        }
    }
    cout << dp2.query(n,n) << "\n";
}
 