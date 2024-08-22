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
    return min(a, b);
}

int el(){
    return INF_INT;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> ac;
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        int l, r;
        cin >> l >> r;
        vp.push_back({l, r});
        ac.push_back(l);
        ac.push_back(r);
        ac.push_back(r+1);
    }
    sort(ac.begin(), ac.end());
    ac.resize(unique(ac.begin(), ac.end()) - ac.begin());
    int c = 0;
    map<int,int> mp;
    for(auto x: ac){
        mp[x] = ++c;
    }
    SegmentTree<int, op, el> st(c+1);
    for(int i=0;i<n;i++){
        auto [l, r] = vp[i];
        st.update(mp[l], 1);
        st.update(mp[r+1], -1);
    }
    for(int i=2;i<=c;i++){
        st.update(i, st.query(i-1, i-1));
    }
    for(int i=0;i<n;i++){
        auto [l, r] = vp[i];
        if(st.query(mp[l], mp[r]) >= 2){
            cout << i+1 << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}
