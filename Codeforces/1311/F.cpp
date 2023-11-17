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

ll op(ll a, ll b){
    return a + b;
}

ll el(){
    return 0LL;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<ll,ll>> vp(n);
    vector<int> v(n);
    for(int i=0;i<n;i++){
         cin >> vp[i].first;
         v[i] = vp[i].first;
    }
    for(int i=0;i<n;i++) cin >> vp[i].second;
    sort(vp.begin(), vp.end(), [&](pair<ll,ll> u, pair<ll,ll> v){
        if(u.second != v.second) return u.second < v.second;
        else return u.first < v.first;
    });
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int m = v.size();
    map<int,int> mp;
    for(int i=0;i<v.size();i++){
        mp[v[i]] = i;
    }
    SegmentTree<ll, op, el> st1(m), st2(m);
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(mp[vp[i].first]){
            ans += st1.query(0, mp[vp[i].first]-1) * vp[i].first - st2.query(0, mp[vp[i].first]-1);
        }
        st1.update(mp[vp[i].first], 1);
        st2.update(mp[vp[i].first], vp[i].first);
    }
    cout << ans << "\n";
}
