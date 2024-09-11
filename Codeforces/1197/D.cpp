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
    SegmentTree(){}
    SegmentTree(vector<T> &v){
        n = v.size();
        st.resize(2*n);
        build(v);
    }
    SegmentTree(ll sz){
        n = sz;
        st.resize(2*n, nullel());
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

const int N = 3e5+3;
ll ps[N];

SegmentTree<ll, op, el> st[11]; 
ll aux[11];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m, k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        if(i != 0) ps[i] = ps[i-1];
        int x;
        cin >> x;
        ps[i] += x;
    }
    for(int i=0;i<m;i++){
        st[i] = SegmentTree<ll, op, el>(n);
    }
    for(int i=0;i<n;i++){
        st[i % m].update(i, ps[i] - k * (i/m + 1));
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll cur = st[j].query(i, n-1);
            if(i != 0) cur -= ps[i-1];
            cur += aux[j];
            ans = max(ans, cur);
        } 
        aux[i % m] += k;
    }
    cout << ans << "\n";
}
