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
    return -INF_INT;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input   
    int n;
    cin >> n;
    vector<pair<int, int>> vp;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        vp.push_back({x, i});
    }
    vector<int> aux(n+2, -INF_INT);
    sort(vp.begin(), vp.end()); 
    vector<int> ans(n+1, INF_INT);
    auto solve = [&](int fl){
        SegmentTree<int, op, el> st1(aux), st2(aux);
        for(auto [px, j] : vp){
            ans[j] = min({ans[j], fl*px + j - st1.query(0, j-1), fl*px - j - st2.query(j+1, n+1)});
            st1.update(j, fl*px + j);
            st2.update(j, fl*px - j);
        }
    };
    solve(1);
    reverse(vp.begin(), vp.end());
    solve(-1);
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}
