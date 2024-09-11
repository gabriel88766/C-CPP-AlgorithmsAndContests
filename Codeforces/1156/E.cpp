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

int opmx(int a, int b){
    return max(a, b);
}

int elmx(){
    return 0;
}
const int N = 2e5+3;
int p[N], invp[N];
ll ans = 0;
SegmentTree<int, opmx, elmx> st(1);

void solve(int l, int r){
    if(l >= r) return;
    int gr = st.query(l, r); 
    int m = invp[gr];
    int sz1 = m-l;
    int sz2 = r-m;
    if(sz1 < sz2){
        for(int i=l;i<m;i++){
            int val = gr - p[i];
            if(invp[val] > m && invp[val] <= r) ans++;
        }
    }else{
        for(int i=m+1;i<=r;i++){
            int val = gr - p[i];
            if(invp[val] < m && invp[val] >= l) ans++;
        }
    }
    solve(l, m-1);
    solve(m+1, r);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> p[i];
        invp[p[i]] = i;
    }
    st = SegmentTree<int, opmx, elmx>(n+1);
    for(int i=1;i<=n;i++) st.update(i, p[i]);
    solve(1, n);
    cout << ans << "\n";
}
