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
    Mint operator/= (Mint u){ //division untested, MOD not prime, u.v must be coprime with MOD.
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

pair<Mint, Mint> op(pair<Mint, Mint> p1, pair<Mint,Mint> p2){//composite lazy
    //a1x + b1, a2x + b2 => a1(a2x + b2) + b1 => (a1a2)x + (a1b2 + b1)
    Mint aans = p1.first*p2.first;
    Mint bans = p1.first*p2.second + p1.second;
    return {aans, bans};
}

const int N = 5e5+6;
Mint st[4*N];
pair<Mint,Mint> lz[4*N];
ll v[N];
int n;
const pair<Mint, Mint> e = {1, 0};
void build(int l = 1, int r = n, int p = 1){
    lz[p] = e;
    if(l == r){ st[p] = v[l]; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}

void push(int l, int r, int p){
    
    if(lz[p] != e){ //0 can be assigned? change!
        st[p] =  st[p] * lz[p].first + Mint(r - l + 1) * lz[p].second; //RMQ = lz, RSQ, = (r-l+1)*lz
        if(l != r){
            lz[2 * p] = op(lz[p], lz[2*p]); // += increment = update
            lz[2 * p + 1] = op(lz[p], lz[2*p+1]);
        } 
        lz[p] = e;
    }
}

Mint query(int i, int j, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return query(i, j, l, (l + r)/2, 2 * p) + query(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update(int i, int j, ll b, ll c, int l = 1, int r = n, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = {b, c}; push(l, r, p); return;}
    update(i, j, b, c, l, (l + r)/2, 2 * p);
    update(i, j, b, c, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    for(int i=0;i<q;i++){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 0){
            ll b, c;
            cin >> b >> c;
            update(l+1, r, b, c);
        }else{
            cout << query(l+1, r) << "\n";
        }
    }
}
