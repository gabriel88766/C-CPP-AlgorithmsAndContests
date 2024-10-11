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
    return max(a, b);
}

ll el(){
    return 0LL;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll ans = 0;
    ll n, a;
    cin >> n >> a;
    vector<pair<ll, ll>> vp(n+1);
    for(int i=1;i<=n;i++) cin >> vp[i].first >> vp[i].second;
    SegmentTreeLazy<ll, op, el> st(n+1);
    deque<pair<ll, ll>> dq;
    for(int i=n;i>=1;i--){
        st.update(i, n, a); //sum a
        st.update(i, n, -vp[i].second); //cost of choosing v[i]
        //now update max(di, di+1)^2...
        if(i != n){
            ll dif = vp[i+1].first - vp[i].first;
            dif *= dif;
            while(!dq.empty() && dq.front().first <= dif){
                ll lo = dq.front().second;
                ll val = dq.front().first;
                dq.pop_front();
                ll hi;
                if(dq.size()) hi = dq.front().second - 1;
                else hi = n;
                st.update(lo, hi, val);
            }
            ll upl;
            if(dq.size()) upl = dq.front().second - 1;
            else upl = n;
            st.update(i+1, upl, -dif);
            dq.push_front({dif, i+1});
        }
        ans = max(ans, st.query(i, n));
    }
    cout << ans << "\n";
}
