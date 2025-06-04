#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

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
    ll gcd_euclid(ll a, ll b, ll &x, ll &y){ //solves ax+by = g where g = gcd(a,b)
        if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
            x = 1; y = 0;
            return a;
        }
        ll d = gcd_euclid(b, a % b, y, x); //if b > a then this step reverses it
        y -= x * (a/b); 
        return d;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    /*Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}*/
    Mint operator/= (Mint u){ //division , MOD not prime, u.v must be coprime with MOD.
        ll x, y;
        ll g = gcd_euclid(u.v, MOD, x, y);
        assert(g == 1);
        (*this) *= x; 
        return *this;
    }
    bool operator== (const Mint u) const { return v == u.v;}
    bool operator!= (const Mint u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTreeLazy{
    vector<T> st;
    vector<tuple<T, T, T>> lz;
    int n;
    SegmentTreeLazy(ll sz){
        n = sz;
        st.assign(4*n, 0);
        lz.resize(4*n);
    }

    void push(int l, int r, int p){
        if(lz[p] != make_tuple(Mint(0), Mint(0), Mint(0))){ //0 can be assigned? change!
            st[p] += get<0>(lz[p]); 
            if(l != r){
                ll l2 = (l+r)/2 + 1;
                ll dif = l2 - l;
                ll tn = (dif * (dif+1))/2;
                get<0>(lz[2 * p]) += get<0>(lz[p]); 
                get<1>(lz[2 * p]) += get<1>(lz[p]); 
                get<2>(lz[2 * p]) += get<2>(lz[p]); 
                get<0>(lz[2*p+1]) += dif * get<1>(lz[p]) + tn * get<2>(lz[p]) + get<0>(lz[p]);
                //get<0> += g1+g2 + g1+2g2+g1+3g2 + ... + 
                get<1>(lz[2*p+1]) += dif * get<2>(lz[p]) + get<1>(lz[p]);
                get<2>(lz[2*p+1]) += get<2>(lz[p]);
            } 
            lz[p] = {Mint(0), Mint(0), Mint(0)};
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
        if(l >= i && r <= j) {
            //if l == i, then {val, val, val};
            //if l == i+1, then {3val, 2val, val};
            //if l == i+2, then {6val, 3val, val};
            ll ord = l - i + 1;
            ll tn = (ord * (ord+1))/2;
            lz[p] = {val * tn, val * ord, val};
            push(l, r, p); 
            return;
        }
        update(i, j, val, l, (l + r)/2, 2 * p);
        update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); 
    }
    void update(int i, int j, T val){
        update(i, j, val, 0, n-1, 1);
    }
};

Mint op(Mint a, Mint b){
    return a + b;
}

Mint el(){
    return Mint(0);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1);
    SegmentTreeLazy<Mint, op, el> st(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        st.update(i, n, v[i]);
    }
    for(int i=1;i<=q;i++){
        int x;
        cin >> x;
        if(x == 1){
            int val;
            cin >> x >> val;
            st.update(x, n, val - v[x]);
            v[x] = val;
        }else{
            cin >> x;
            cout << st.query(x, x) << "\n";
        }
    }
}
