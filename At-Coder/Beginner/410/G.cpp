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

int op(int a, int b){
    return max(a, b);
}

int el(){
    return 0;
}

const int mid = 400001;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //must be a sequnce [a, b] such that one is increasing and the other is decreasing
    int n;
    cin >> n;
    vector<pair<int, int>> vp;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        vp.push_back({a, b});
        vp.push_back({b-2*n, a});
    }
    sort(vp.begin(), vp.end(), greater<pair<int, int>>());
    //b between -2n and 2n.
    //a between 1 and 2n
    SegmentTree<int, op, el> st(800003);
    for(auto [a, b]: vp){
        //a is decrescent and b is crescent
        // int anb = b - 2*n;
        // cout << a << " " << b << " " << anb << "\n";
        st.update(b+mid, st.query(0, b+mid-1) + 1);
        // st.update(anb + mid, st.query(0, anb+mid-1) + 1);
    }
    int ans = st.query(0, 2*n + mid );
    cout << ans << "\n";
}
