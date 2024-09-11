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

    T query(int i, int j, int l, int r, int p){
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

int op(int a, int b){
    return min(a, b);
}

int el(){
    return INF_INT;
}

const ll inf = 1e12;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> idx;
    vector<ll> a(n+1), b(n+1);
    for(int i=1;i<=n;i++){
        if(s[i] == '('){
            a[i] = 0, b[i] = inf;
        }else if(s[i] == ')'){
            a[i] = inf, b[i] = 0;
        }else{
            idx.push_back(i);
        }
    }
    for(auto x : idx) cin >> a[x] >> b[x];
    ll ans = 0;
    for(int i=1;i<=n;i++) ans += a[i];
    for(int i=1;i<=n;i++) b[i] -= a[i];
    vector<pair<ll, ll>> vp;
    for(int i=1;i<=n;i++){
        vp.push_back({b[i], i});
    }
    sort(vp.begin(), vp.end());
    SegmentTreeLazy<int, op, el> st(n+1);
    for(int i=1;i<=n;i++) st.update(i, i, i/2);
    string sans(n, '.');
    for(auto [val, i] : vp){
        if(st.query(i, i) >= 1){
            sans[i-1] = ')';
            ans += b[i];
            st.update(i, n, -1);
            int val = st.query(i, i);
            if(st.query(i-1, i-1) == val + 1){
                int lo = 1, hi = i-1;
                while(lo != hi){
                    int mid = lo + (hi - lo)/2;
                    if(st.query(mid, i-1) == val + 1) hi = mid;
                    else lo = mid + 1;
                }
                st.update(lo, i-1, -1);
            }
        }else sans[i-1] = '(';
    }
    if(ans < inf){
        cout << ans << "\n";
        cout << sans << "\n";
    }else cout << "-1\n";
}
