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
    return a + b;
}

int el(){
    return 0;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> vp;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        vp.push_back({x, i});
    }
    sort(vp.begin(), vp.end());
    vector<tuple<int, int, int, int, int>> vq;
    vector<int> ans(q);
    for(int i=0;i<q;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vq.push_back({a, b, c, d, i});
        ans[i] = b-a+1;
    }
    sort(vq.begin(), vq.end(), [&](const tuple<int, int, int, int, int> &a, const tuple<int, int, int, int, int> &b){
        return get<3>(a) < get<3>(b);
    });
    SegmentTree<int, op, el> st(n+1);
    int p = 0;
    for(auto &[a, b, c, d, i] : vq){
        while(p < vp.size() && vp[p].first <= d){
            st.update(vp[p].second, 1);
            p++;
        }
        ans[i] -= b-a+1 - st.query(a, b);
    }
    p = n - 1;
    for(int i=1;i<=n;i++) st.update(i, 0);
    sort(vq.begin(), vq.end(), [&](const tuple<int, int, int, int, int> &a, const tuple<int, int, int, int, int> &b){
        return get<2>(a) > get<2>(b);
    });
    for(auto &[a, b, c, d, i] : vq){
        while(p >= 0 && vp[p].first >= c){
            st.update(vp[p].second, 1);
            p--;
        }
        ans[i] -= b-a+1 - st.query(a, b);
    }
    for(int i=0;i<q;i++) cout << ans[i] << "\n";

}
