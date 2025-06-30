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
    return min(a, b);
}

ll el(){
    return INF_LL;
}

const int N = 2e5+3;
ll a[N], b[N], c[N];
ll psa[N], psb[N], psc[N];
ll v[N];
ll dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i] >> c[i];
        b[i] = min(a[i], b[i]);
        c[i] = min(a[i], c[i]);
        psa[i] = psa[i-1] + a[i];
        psb[i] = psb[i-1] + b[i];
        psc[i] = psc[i-1] + c[i];
    }
    vector<ll> aux(n+1, INF_LL);
    aux[0] = 0;
    SegmentTree<ll, op, el> st(aux);
    memset(dp, 63, sizeof(dp));
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        dp[v[i]] = psb[v[i] - 1];
        dp[v[i]] = min(psb[v[i] - 1], st.query(0, v[i]-1) + psa[v[i] - 1]);
        st.update(v[i], dp[v[i]] - psa[v[i]]);
    }
    ll ans = INF_LL;
    for(int i=1;i<=n;i++){
        ans = min(ans, dp[i] + psc[n] - psc[i]);
    }
    cout << ans << "\n";
}   
