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

ll ops(ll a, ll b){
    return a + b;
}

ll els(){
    return 0LL;
}



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
            st[p] +=  lz[p]; //RMQ = lz, RSQ, = (r-l+1)*lz
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
    int query2(int i, int j, ll y, int l, int r, int p){
        if(j < l || i > r) return INF_INT; //identity element;
        push(l, r, p);
        if(l == r){
            if(st[p] <= y) return l;
            else return INF_INT;
        }
        int m = (l + r)/2;
        push(l, m, 2*p);

        if(st[2*p] <= y){
            int ans = query2(i, j, y, l, (l + r)/2, 2 * p);
            if(ans != INF_INT) return ans;
            else{
                return query2(i, j, y, (l + r)/2 + 1, r, 2 * p + 1);
            }
        }
        push(m+1, r, 2*p+1);
        if(st[2*p+1] <= y){
            return query2(i, j, y, (l + r)/2 + 1, r, 2 * p + 1);
        }else return INF_INT;
    }
    int query2(int i, int j, ll y){
        return query2(i, j, y, 0, n-1, 1);
    }
};

ll opm(ll a, ll b){
    return min(a, b);
}

ll elm(){
    return INF_LL;
}

ll calcC(ll a, ll b){
    if(b == 1) return INF_LL;
    else{
        return (a + (b-2))/(b-1);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> a(n+1), b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    SegmentTree<ll, ops, els> st1(a);
    for(int i=1;i<=n;i++) cin >> b[i];
    SegmentTreeLazy<ll, opm, elm> stm(n+1);
    ll sum = 0;
    for(int i=1;i<=n;i++){
        stm.update(i, i, calcC(a[i], b[i]));
        stm.update(i, i, -sum);
        sum += a[i];
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            ll oldc = calcC(a[l], b[l]);
            if(l < n) stm.update(l+1, n, a[l] - r);
            a[l] = r;
            st1.update(l, r);
            ll newc = calcC(a[l], b[l]);
            stm.update(l, l, newc - oldc);
        }else if(t==2){
            ll oldc = calcC(a[l], b[l]);
            b[l] = r;
            ll newc = calcC(a[l], b[l]);
            stm.update(l, l, newc - oldc);
        }else{
            ll ans = 0;
            while(l <= r){
                ll aux = st1.query(0, l-1) - ans;
                int lo = stm.query2(l, r, -aux);
                if(lo <= r){
                    if(lo > l) ans += st1.query(l, lo-1);
                    ans *= b[lo];
                    l = lo + 1;
                }else{
                    ans += st1.query(l, r);
                    break;
                }
            }
            cout << ans << "\n";

        }

    }
}
