#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3;

struct Mint{
    ll v;
    //static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ v = (u >= 0 ? u % MOD : u % MOD + MOD);}
    Mint pow(ll u){
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
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTreeLazy{
    vector<T> st;
    vector<pair<T,T>> lz;
    int n;
    SegmentTreeLazy(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        lz.assign(4*n, {Mint(1LL), Mint(0LL)});
        build(v, 0, n-1, 1);
    }
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, nullel());
        lz.assign(4*n, {Mint(1LL), Mint(0LL)});
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){ st[p] = v[l]; return; }
        build(v, l, (l+r)/2, 2 * p);
        build(v, (l+r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }

    void push(int l, int r, int p){
        if(lz[p].first != 1 || lz[p].second != 0){ //0 can be assigned? change!
            st[p] = Mint(r - l + 1) * lz[p].second + st[p] * lz[p].first; //RMQ = lz, RSQ, = (r-l+1)*lz
            if(l != r){
                lz[2 * p] = {lz[2*p].first*lz[p].first, lz[2*p].second*lz[p].first + lz[p].second};
                lz[2 * p + 1] = {lz[2*p + 1].first*lz[p].first, lz[2*p + 1].second*lz[p].first + lz[p].second};
            } 
            lz[p] = {Mint(1LL), Mint(0LL)};
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
    void update(int i, int j, T b, T c, int l, int r, int p){
        push(l, r, p);
        if(j < l || i > r) return;
        if(l >= i && r <= j) {lz[p] = {b, c}; push(l, r, p); return;}
        update(i, j, b, c, l, (l + r)/2, 2 * p);
        update(i, j, b, c, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, T b, T c){
        update(i, j, b, c, 0, n-1, 1);
    }
};


Mint op(Mint a, Mint b){
    return a + b;
}

Mint el(){
    return Mint(0LL);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input

    int n, q;
    cin >> n >> q;
    vector<Mint> v(n);
    for(int i=0;i<n;i++) cin >> v[i].v;
    SegmentTreeLazy<Mint, op, el> st(v);
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t == 0){
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            st.update(l, r-1, Mint(b), Mint(c));
        }else{
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r-1) << "\n";
        }
    }
}   
