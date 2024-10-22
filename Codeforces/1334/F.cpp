#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTreeLazy{
    vector<T> st, lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, 0);
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, 0);
        lz.assign(4*n, 0);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != 0){ //0 can be assigned? change!
            st[p] += lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
            if(l != r){
                lz[2 * p] += lz[p]; // += increment = update
                lz[2 * p + 1] += lz[p];
            } 
            lz[p] = 0;
        }
    }

    ll query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return nullel();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, T val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, T val){
        update(i, j, val, 0, n-1, 1);
    }
};

ll op(ll a, ll b){
    return min(a, b);
}

ll el(){
    return INF_LL;
}

const ll x = 1e17;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n;
    vector<int> a(n+1), p(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> p[i];
    cin >> m;
    vector<int> b(m+2);
    for(int i=1;i<=m;i++) cin >> b[i];
    b[m+1] = INF_INT;
    SegmentTreeLazy<ll, op, el> dp(m+1);
    dp.update(1, m, 5*x);
    for(int i=1;i<=n;i++){
        int ind = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if(b[ind] == a[i]){
            if(p[i] < 0 && ind <= m) dp.update(ind, m, p[i]);
            ll valb = dp.query(ind-1,ind-1);
            ll valc = dp.query(ind,ind);
            if(valb < valc){
                dp.update(ind, ind, -dp.query(ind,ind));
                dp.update(ind,ind,valb);
            }
            dp.update(0, ind-1, p[i]);
            
        }else{
            if(p[i] >= 0) dp.update(0, ind - 1, p[i]); 
            else dp.update(0, m, p[i]);
        }
    }
    ll ans = dp.query(m, m);
    if(ans < x) cout << "YES\n" << ans << "\n";
    else cout << "NO\n";
}   