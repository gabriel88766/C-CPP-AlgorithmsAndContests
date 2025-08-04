#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(int u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
        Mint ans = 1;
        Mint aux = *this;
        while(u){
            if(u & 1) ans *= aux;
            aux *= aux;
            u >>= 1;
        }
        return ans;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint& operator*= (const Mint &u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint& operator+= (const Mint &u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint& operator-= (const Mint &u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint& operator/= (const Mint &u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint &u) const { return v == u.v;}
    bool operator!= (const Mint &u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

template<typename T, typename S, T (*op)(T, T), T (*el)(), S (*id)(),\
 S (*composition)(S, S), T (*apply)(T, S, int)>
struct SegmentTreeLazy{
    vector<T> st;
    vector<S> lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, id());
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, el());
        lz.assign(4*n, id());
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p] != id()){ //0 can be assigned? change!
            st[p] = apply(st[p], lz[p], r-l+1);
            if(l != r){
                lz[2 * p] = composition(lz[2*p], lz[p]); // += increment = update
                lz[2 * p + 1] = composition(lz[2*p + 1], lz[p]);
            } 
            lz[p] = id();
        }
    }

    T query(int i, int j, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return el();
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, int j, S val, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = val; push(l, r, p); return;}
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, S val){
        update(i, j, val, 0, n-1, 1);
    }
};

Mint op(Mint a, Mint b){
    return a + b;
}

Mint el(){
    return Mint(0);
}

pair<Mint, int> id(){
    return {Mint(0), -1}; //-1 means don't update. anything else means update
}

pair<Mint, int> composition(pair<Mint, int> a, pair<Mint, int> b){
    return b;
}

Mint apply(Mint stv, pair<Mint, int> lzv, int len){
    return lzv.first * len;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<Mint> ini(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        ini[i] = x;
    }
    SegmentTreeLazy<Mint, pair<Mint, int>, op, el, id, composition, apply> st(ini);
    for(int i=1;i<=m;i++){
        int l, r;
        cin >> l >> r;
        auto qr = st.query(l, r);
        auto avg = qr / (r - l + 1);
        st.update(l, r, make_pair(avg, 1));
    }
    for(int i=1;i<=n;i++){
        cout << st.query(i, i) << " ";
    }
    cout << "\n";
}
