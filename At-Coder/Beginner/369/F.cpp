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
        build();
    }
    void build(vector<T> &v){
        for(int i=n;i<2*n;i++) st[i] = v[i-n];
        for(int i=n-1;i>=1;i--) st[i] = op(st[2*i], st[2*i+1]); //merge op
    }
    void build(){
        for(int i=n;i<2*n;i++) st[i] = nullel();
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

pair<int,int> op(pair<int,int> a, pair<int,int> b){
    return max(a, b);
}

pair<int,int> el(){
    return make_pair(-INF_INT, -INF_INT);
}

const int N = 2e5+3;
int dp[N];
int par[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int,int>> vp(n+2);
    vp[0] = {1, 1};
    for(int i=1;i<=n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    vp[n+1] = {h, w};
    sort(vp.begin(), vp.end());
    SegmentTree<pair<int, int>, op, el> st(N);
    st.update(1, make_pair(-1, 0));
    for(int i=1;i<=n+1;i++){
        auto [y, x] = vp[i];
        auto p = st.query(1, x);
        par[i] = p.second;
        dp[i] = p.first + 1;
        st.update(x, make_pair(dp[i], i));
    }
    auto ans = st.query(w, w);
    cout << ans.first << "\n";
    string s = "";
    int cur = n+1;
    while(cur != 0){
        int nxt = par[cur];
        int dx = abs(vp[nxt].second - vp[cur].second);
        int dy = abs(vp[nxt].first - vp[cur].first);
        for(int i=0;i<dx;i++) s += 'R';
        for(int i=0;i<dy;i++) s += 'D';
        cur = nxt;
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
}   
