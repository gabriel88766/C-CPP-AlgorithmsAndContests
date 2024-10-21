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

ll op(ll a, ll b){
    return a + b;
}

ll el(){
    return 0LL;
}

const int N = 3e5+3;
ll v[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    set<int> sh;
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<ll,ll>> vp(m);
    for(int i=0;i<m;i++){
        cin >> vp[i].first;
    }
    for(int i=0;i<m;i++) cin >> vp[i].second;
    for(int i=0;i<m;i++){
        sh.insert(vp[i].first);
        v[vp[i].first] = vp[i].second; 
    }
    SegmentTree<ll, op, el> st(n+1);
    for(auto x : sh){
        if(x != n){
            ll d = *sh.upper_bound(x) - x - 1;
            d = (d * (d+1))/2;
            st.update(*sh.upper_bound(x), d*v[x]);
        }
    }
    for(int i=0;i<q;i++){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            v[l] = r;
            int bv = *prev(sh.lower_bound(l));
            int nv = *sh.lower_bound(l);
            ll d1 = nv - l - 1;
            ll d2 = l - bv - 1;
            d1 = (d1 * (d1+1))/2;
            d2 = (d2 * (d2+1))/2;
            st.update(l, v[bv] * d2);
            st.update(nv, v[l] * d1);
            sh.insert(l);
        }else{
            ll ans = 0;
            int lv = *sh.lower_bound(l);
            int rv = *prev(sh.upper_bound(r));
            if(lv > rv){
                ll d1 = lv - l;
                ll d2 = lv - r;
                ans += (((d1-d2+1) * (d1+d2))/2) * v[rv];
                cout << ans << "\n";
                continue;
            }


            if(lv + 1 <= rv) ans = st.query(lv+1, rv);
            ll d1 = lv - l;

            d1 = (d1 * (d1+1))/2;
            // cout << lv << " " << rv << " ";
            if(d1){
                ans += d1 * v[*prev(sh.lower_bound(l))];
            }
            if(rv != r){
                ll d1 = *sh.upper_bound(r) - rv - 1;
                ll d2 =  *sh.upper_bound(r) - r;
                ans += (((d1-d2+1) * (d1+d2))/2) * v[rv];
            }
            cout << ans << "\n";
        }
    }
}
