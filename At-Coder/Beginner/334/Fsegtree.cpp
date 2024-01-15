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

double op(double a, double b){
    return min(a, b);
}

double el(){
    return 1e50;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    ll sx, sy;
    cin >> sx >> sy;
    vector<pair<ll, ll>> vp(n);
    for(int i=0;i<n;i++) cin >> vp[i].first >> vp[i].second;
    double ans = 0;
    for(auto [x, y] : vp){
        ll dx = abs(x - sx);
        ll dy = abs(y - sy);
        ans += 2*sqrt(dx*dx + dy*dy);
    }
    cout << fixed << setprecision(15);
    if(k == 1){
        cout << ans << "\n";
        return 0;
    }
    vector<double> difs(n);
    double sum = 0;
    for(int i=1;i<n;i++){
        ll dx1 = abs(vp[i].first - sx);
        ll dy1 = abs(vp[i].second - sy);
        ll dx2 = abs(vp[i-1].first - sx);
        ll dy2 = abs(vp[i-1].second - sy);
        ll dx3 = abs(vp[i].first - vp[i-1].first);
        ll dy3 = abs(vp[i].second - vp[i-1].second);
        double d = sqrt(dx1*dx1 + dy1*dy1) + sqrt(dx2*dx2+dy2*dy2) - sqrt(dx3*dx3 + dy3*dy3);
        difs[i] = d; 
        sum += d;
    }
    SegmentTree<double, op, el> dp(n+1);
    for(int i=1;i<n;i++){
        double cur = dp.query(max(0, i-k), i-1);
        //cout << cur  << "\n";
        dp.update(i, cur + difs[i]);
    }
    ans -= sum;
    ans += dp.query(n-k,n-1);
    cout << ans << "\n";
}
