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
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 2e5+3;
const int sqrtN = 500; //200000 = 500*400
Mint a[N], b[N];
Mint bl[N/sqrtN+1];
Mint lb[N/sqrtN+1], la[N/sqrtN+1];
Mint sb[N/sqrtN+1], sa[N/sqrtN+1];
int n;

void build(){
    for(int i=1;i<=n;i++){
        bl[i/sqrtN] += a[i]*b[i];
        sa[i/sqrtN] += a[i];
        sb[i/sqrtN] += b[i];
    }
}

Mint query(int aa, int bb){
    int l = (aa/sqrtN+1)*sqrtN;
    int r = (bb/sqrtN)*sqrtN;
    Mint ans = 0;
    if(r <= l){
        for(int i=aa;i<=bb;i++) ans += (a[i] + la[i/sqrtN]) * (b[i] + lb[i/sqrtN]);
    }else{
        for(int i=aa;i<l;i++) ans += (a[i] + la[i/sqrtN]) * (b[i] + lb[i/sqrtN]);
        for(int i=r;i<=bb;i++) ans += (a[i] + la[i/sqrtN]) * (b[i] + lb[i/sqrtN]);
        l /= sqrtN, r /= sqrtN;
        for(int i=l;i<r;i++){
            ans += bl[i];
        }
    }
    return ans;
}

void update_a(int aa, int bb, Mint x){ 
    int l = (aa/sqrtN+1)*sqrtN;
    int r = (bb/sqrtN)*sqrtN;
    if(r <= l){
        for(int i=aa;i<=bb;i++){
            bl[i/sqrtN] += x*(b[i] + lb[i/sqrtN]);
            sa[i/sqrtN] += x;
            a[i] += x;
        }
    }else{
        for(int i=aa;i<l;i++){
            bl[i/sqrtN] += x*(b[i] + lb[i/sqrtN]);
            sa[i/sqrtN] += x;
            a[i] += x;
        }
        for(int i=r;i<=bb;i++){
            bl[i/sqrtN] += x*(b[i] + lb[i/sqrtN]);
            sa[i/sqrtN] += x;
            a[i] += x;
        }
        l /= sqrtN, r /= sqrtN;
        for(int i=l;i<r;i++){
            la[i] += x;
            bl[i] += x * sb[i];
            sa[i] += x * sqrtN;
        }
    }
}

void update_b(int aa, int bb, Mint x){ 
    int l = (aa/sqrtN+1)*sqrtN;
    int r = (bb/sqrtN)*sqrtN;
    if(r <= l){
        for(int i=aa;i<=bb;i++){
            bl[i/sqrtN] += x*(a[i] + la[i/sqrtN]);
            sb[i/sqrtN] += x;
            b[i] += x;
        }
    }else{
        for(int i=aa;i<l;i++){
            bl[i/sqrtN] += x*(a[i] + la[i/sqrtN]);
            sb[i/sqrtN] += x;
            b[i] += x;
        }
        for(int i=r;i<=bb;i++){
            bl[i/sqrtN] += x*(a[i] + la[i/sqrtN]);
            sb[i/sqrtN] += x;
            b[i] += x;
        }
        l /= sqrtN, r /= sqrtN;
        for(int i=l;i<r;i++){
            lb[i] += x;
            bl[i] += x * sa[i];
            sb[i] += x * sqrtN;
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        ll x;
        cin >> x;
        a[i] = x;
    }
    for(int i=1;i<=n;i++){
        ll x;
        cin >> x;
        b[i] = x;
    }
    build();

    for(int i=0;i<q;i++){
        int tt, x, l, r;
        cin >> tt >> l >> r;
        if(tt == 1){
            cin >> x;
            update_a(l, r, x);
        }else if(tt == 2){
            cin >> x;
            update_b(l, r, x);
        }else{
            cout << query(l, r) << "\n";
        }
    }
}
