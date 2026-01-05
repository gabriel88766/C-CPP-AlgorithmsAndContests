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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> cds;
    vector<pair<int, int>> pts(n);
    for(int i=0;i<n;i++){
        cin >> pts[i].first >> pts[i].second;
        cds.push_back(pts[i].second);
    }
    cds.push_back(-1);
    sort(cds.begin(), cds.end());
    cds.resize(unique(cds.begin(), cds.end()) - cds.begin());
    sort(pts.begin(), pts.end(), [&](pair<int, int> a, pair<int, int> b){
        if(a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    });
    SegmentTree<int, op, el> st(cds.size());
    int ans = 0;
    for(auto [a, b] : pts){
        int cy = lower_bound(cds.begin(), cds.end(), b) - cds.begin();
        int cur = st.query(0, cy-1) + 1;
        ans = max(ans, cur);
        st.update(cy, cur);
    }
    cout << ans << "\n";
}
