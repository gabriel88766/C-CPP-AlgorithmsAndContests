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

int opmn(int a, int b){
    return min(a, b);
}

int elmn(){
    return INF_INT;
}

int opmx(int a, int b){
    return max(a, b);
}

int elmx(){
    return -INF_INT;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        string s;
        cin >> n >> m >> s;
        vector<int> ps(n+2);
        for(int i=1;i<=n;i++){
            if(s[i-1] == '-') ps[i] = -1;
            else ps[i] = 1;
            ps[i] += ps[i-1];
        }
        ps[n+1] = ps[n];
        SegmentTree<int, opmn, elmn> stmn(ps);
        SegmentTree<int, opmx, elmx> stmx(ps);
        for(int i=1;i<=m;i++){
            int l, r;
            cin >> l >> r;
            int mn1 = stmn.query(0, l-1);
            int mx1 = stmx.query(0, l-1);
            int mn2 = stmn.query(r+1, n+1) - ps[r] + ps[l-1];
            int mx2 = stmx.query(r+1, n+1) - ps[r] + ps[l-1];
            int mn = min(mn1, mn2);
            int mx = max(mx1, mx2);
            cout << mx-mn+1 << "\n";
        }
    }
}
