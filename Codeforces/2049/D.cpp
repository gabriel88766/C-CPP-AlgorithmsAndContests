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
    return min(a, b);
}

ll el(){
    return INF_LL;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){ //O(200^3 * log 200)
        int n, m;
        ll k;
        cin >> n >> m >> k;
        vector<vector<ll>> gr(n, vector<ll>(m));
        vector<vector<ll>> dp(n, vector<ll>(m, INF_LL));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> gr[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int js=0;js<m;js++){ //jmp size, at most m-1
                //init 0-js is ok
                //1-js+1 is k + ok
                //2-js+2 is 2*k + ok
                //how to update:
                // all should made be - k
                // then update only the current to + m*k
                SegmentTree<ll, op, el> st(m);
                ll cs = 0;
                for(int j=0;j<=js;j++) cs += gr[i][j];
                for(int j=0;j<m;j++){
                    st.update(j, cs + k*j);
                    cs -= gr[i][j];
                    cs += gr[i][(j + js + 1) % m];
                }
                int jmax = (i == 0 ? 0 : m-js-1);
                ll fac = 0;
                for(int j=0;j<=jmax;j++){
                    ll cur = (i == 0 ? 0 : dp[i-1][j]);
                    dp[i][j + js] = min(dp[i][j+js], cur + st.query(0, m-1) + fac);
                    fac -= k;
                    st.update(j, m*k);
                }
            }
        }
        cout << dp[n-1][m-1] << "\n";
    }
}
