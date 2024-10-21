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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n+1);
        vector<vector<int>> pos(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        SegmentTree<int, opmx, elmx> smx(n+1); //prev
        vector<int> l(n+1), r(n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<pos[i].size();j++){
                smx.update(pos[i][j], pos[i-1][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<pos[i].size();j++){
                smx.update(pos[i][j], elmx());
            }
            for(int j=1;j<pos[i].size();j++){
                r[pos[i][j]] = smx.query(pos[i][j-1], pos[i][j]);
            }

            for(int j=1;j<pos[i].size();j++){
                smx.update(pos[i][j], pos[i-1][j]);
            }
        }
        vector<int> ans(n+1);
        auto solve = [&](int l, int r, int opmn, int opmx){
            if(l > r) return;
            int fl = n+1;
            int m = (l + r)/2;
            for(int j=opmn; j<=opmx;j++){
                //check if j make l - j be NO
                //if so, fl = j and break
                if(j == n+1) break;

            }
            ans[m] = fl;
            solve(l, m-1, opmn, fl);
            solve(m+1, r, fl, opmx);
        };
        solve(1, n, 1, n+1);
        for(int i=0;i<q;i++){
            int l, r;
            cin >> l >> r;
            if(ans[l] > r) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
