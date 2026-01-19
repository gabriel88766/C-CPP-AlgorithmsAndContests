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
    return max(a, b);
}

ll el(){
    return 0;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m;
    cin >> n >> m;
    vector<ll> w(n+1);
    ll mw = 0;
    for(int i=1;i<=n;i++){
        cin >> w[i];
        mw = max(mw, w[i]);
    }
    ll mv = INF_LL;
    vector<pair<ll, ll>> vp;
    vector<ll> cds = {0};
    for(int i=1;i<=m;i++){
        ll l, v;
        cin >> l >> v;
        cds.push_back(v);
        vp.push_back({l, v});
        mv = min(mv, v);
    }
    if(mv < mw){
        cout << "-1\n";
        return 0;
    }
    
    sort(cds.begin(), cds.end());
    cds.resize(unique(cds.begin(), cds.end()) - cds.begin());
    SegmentTree<ll, op, el> st(cds.size());

    for(auto [l, v] : vp){
        ll cc = lower_bound(cds.begin(), cds.end(), v) - cds.begin();
        if(l > st.query(cc, cc)) st.update(cc, l);
    }
    ll ans = INF_LL;
    vector<int> perm;
    for(int j=1;j<=n;j++) perm.push_back(j);
    vector<int> vx = {1, 2, 3, 4, 5, 6, 7, 8};
    do{
        vector<ll> d(n, 0);
        ll cur = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                //get sum w
                ll csw = 0;
                for(int u=j;u<=i;u++) csw += w[perm[u]];
                //get dist min
                ll dmn = 0;
                for(int u=j+1;u<i;u++) dmn += d[u];
                int xx = lower_bound(cds.begin(), cds.end(), csw) - cds.begin() - 1;
                ll dc = st.query(0, xx);
                // if(perm == vx) cout << i << " " << j << " " << dmn << " " << dc << ""
                d[i] = max(d[i], dc - dmn);
            }



            cur += d[i];
        }
        ans = min(ans, cur);
    }while(next_permutation(perm.begin(), perm.end()));
    cout << ans << "\n";
}   
