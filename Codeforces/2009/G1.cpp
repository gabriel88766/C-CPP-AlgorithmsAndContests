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

int op(int a, int b){
    return max(a, b);
}

int el(){
    return 0;
}

struct Query{
    int l, r, j;
    bool operator< (const Query &q) const{
        return r < q.r;
    }
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];

        vector<vector<int>> hs(2*n+5);
        vector<int> val(n+1);
        vector<int> ans(n+1);
        for(int i=1;i<=n;i++){
            hs[v[i]-i+n].push_back(i);
            val[i] = v[i] - i + n;
        }
        SegmentTree<int, op, el> st(2*n+5);
        for(int i=1;i<=n;i++){
            st.update(val[i], 1);
            if(i > k) st.update(val[i-k], -1);
            if(i >= k) ans[i] = st.query(1, 2*n-1);
        }
        // hs between 1 and 2*n-1
        //-4 = -3,-2,-1,0,1
        //0 = 1,2,3,4,5
        //4 = 5,6,7,8,9
        for(int i=0;i<q;i++){
            int l, r;
            cin >> l >> r;
            cout << k-ans[r] << "\n";
        }
    }
}
