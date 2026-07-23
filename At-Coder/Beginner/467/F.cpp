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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1), b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    vector<tuple<int, int, int>> upd(q+1);
    vector<tuple<int, int, int>> nd;
    for(int i=1;i<=n;i++){
        nd.push_back({b[i], i, 0});
    }
    
    for(int i=1;i<=q;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 2){
            nd.push_back({c, b, i});
        }
        upd[i] = {a, b, c};
    }
    vector<int> idxb(nd.size());
    vector<int> nb(q+1);
    sort(nd.begin(), nd.end());
    reverse(nd.begin(), nd.end());
    SegmentTreeLazy<ll, op, el> st(nd.size()); // max
    int m = nd.size() - 1;
    for(int i = 0; i <= m; i++){
        auto [x, b, c] = nd[i];
        if(c == 0){
            idxb[b] = i;
            st.update(i, i, x);
            st.update(i, m, a[b]);
        }else{
            nb[c] = i;
        }
    }
    for(int i=1;i<=q;i++){
        auto [tq, j, x] = upd[i];
        if(tq == 1){
            st.update(idxb[j], m, -a[j]);
            a[j] = x;
            st.update(idxb[j], m, a[j]);
        }else{
            st.update(idxb[j], idxb[j], -b[j]);
            st.update(idxb[j], m, -a[j]);
            idxb[j] = nb[i];
            b[j] = x;
            st.update(idxb[j], idxb[j], b[j]);
            st.update(idxb[j], m, a[j]);
        }
        cout << st.query(0, m) << "\n";
    }

}
