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

const int N = 2e5+6;
Mint st[4*N];
tuple<Mint, Mint, Mint> lz[4*N];
Mint v[N];
int n;

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ st[p] = v[l]; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}

void push(int l, int r, int p){
    auto [x, y, z] = lz[p];
    if(x.v != 1 || y.v != 0 || z.v != 1){ //0 can be assigned? change!
        auto [a, b, c] = lz[p];
        st[p] = (st[p] * a + b)/c;
        if(l != r){
            get<0>(lz[2*p]) *= get<0>(lz[p]);
            get<1>(lz[2*p]) = get<1>(lz[2*p]) * get<0>(lz[p]) + get<1>(lz[p]) * get<2>(lz[2*p]);
            get<2>(lz[2*p]) *= get<2>(lz[p]);
            get<0>(lz[2*p+1]) *= get<0>(lz[p]);
            get<1>(lz[2*p+1]) = get<1>(lz[2*p+1]) * get<0>(lz[p]) + get<1>(lz[p]) * get<2>(lz[2*p+1]);
            get<2>(lz[2*p+1]) *= get<2>(lz[p]);
        } 
        lz[p] = make_tuple(Mint(1), Mint(0), Mint(1));
    }
}

Mint query(int i, int j, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return query(i, j, l, (l + r)/2, 2 * p) + query(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update(int i, int j, int val, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = {j-i, val, j-i+1}; push(l, r, p); return;}
    update(i, j, val, l, (l + r)/2, 2 * p);
    update(i, j, val, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        ll aux;
        cin >> aux;
        v[i] = aux;
    }
    build();
    for(int i=0;i<4*N;i++){
        lz[i] = {1, 0, 1};
    }
    for(int i=0;i<m;i++){
        int l, r, x;
        cin >> l >> r >> x;
        update(l, r, x);
    }
    for(int i=1;i<=n;i++) cout << query(i, i) << " ";
    cout << "\n";
}
