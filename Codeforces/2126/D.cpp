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

pair<int, int> op(pair<int, int> a, pair<int, int> b){
    return max(a, b);
}

pair<int, int> el(){
    return {-1, -1};
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<tuple<int, int, int>> cs(n+1);
        for(int i=1;i<=n;i++){
            int l, r, v;
            cin >> l >> r >> v;
            cs[i] = {l, r, v};
        }
        sort(cs.begin() + 1, cs.end());
        SegmentTree<pair<int, int>, op, el> st(n+1);
        for(int i=1;i<=n;i++){
            auto [a,b,c] = cs[i];
            st.update(i, {b, i});
        }
        st.update(0, {-1,-1});
        cs[0] = {0, 0, k};
        queue<int> q;
        q.push(0);
        int ans = k;
        while(q.size()){
            auto u = q.front();
            q.pop();
            int val = get<2>(cs[u]);
            ans = max(ans, val);
            auto idmx = lower_bound(cs.begin(), cs.end(), make_tuple(val, INF_INT, INF_INT)) - cs.begin();
            idmx--;

            while(st.query(0, idmx).first >= val){
                auto px = st.query(0, idmx);
                q.push(px.second);
                st.update(px.second, {-1, -1});
            }
        }
        cout << ans << "\n";
    }
}
