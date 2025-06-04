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
    int n, d, r;
    cin >> n >> d >> r;
    SegmentTree<int, op, el> st(n+1);
    vector<pair<int, int>> vh;
    for(int i=1;i<=n;i++){
        int h;
        cin >> h;
        vh.push_back({h, i});
    }
    sort(vh.begin(), vh.end());
    set<tuple<int, int, int>> upd;
    int ans = 0;
    for(auto &[h, j] : vh){
        while(upd.size() && get<0>(*upd.begin()) <= h - d){
            st.update(get<1>(*upd.begin()), get<2>(*upd.begin()));
            upd.erase(upd.begin());
        }
        int qr = st.query(max(j - r, 1), min(j + r, n));
        ans = max(ans, qr + 1);
        upd.insert({h, j, qr + 1});
    }
    cout << ans-1 << "\n";
}
