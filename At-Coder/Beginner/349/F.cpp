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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ull mult(ull a, ull  b, ull  m){
    __int128 res = (unsigned __int128)a * b % m;
    return (ull)res;
}

ull binpow(ull a, ull b, ull m){
    a %= m;
    ull ans = 1;
    while(b){
        if(b & 1) ans = mult(ans, a, m);
        a = mult(a, a, m);
        b >>= 1;
    }
    return ans;
}

bool check_composite(ull n, ull a, ull d, int s){
    ull res = binpow(a, d, n);
    if(res == 1 || res == (n-1)) return false;
    for(int r=1;r<s;r++){
        res = mult(res, res, n);
        if(res == (n-1)) return false;
    }
    return true;
}

bool isPrime(ull n){
    if(n < 2) return false;
    int s = 0;
    ull d = n - 1;
    while(!(d & 1)){
        d >>= 1;
        s++;
    }
    for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if (n == a) return true;
        if(check_composite(n,a,d,s)) return false;
    }
    return true;
}
//end miler rabin

//begin pollard rho finds 
ull gcd(ull a, ull b){
    while(b){ ull c = a % b; a = b; b = c; }
    return a;
}
ull funct(ull x, ull c, ull mod){
    x = mult(x,x,mod);
    x += c;
    return x > mod ? x - mod : x;
}

ull rho(ull n, ull c = 1){
    if(!(n&1)) return 2;
    ull x = 2, y = 2;
    ull g = 1;
    while(g == 1){
        x = funct(x,c,n);
        y = funct(y,c,n);
        y = funct(y,c,n);
        g = gcd((x > y ? x-y : y-x), n);
    }
    if(g == n) return rho(g, rng());
    return isPrime(g) ? g : rho(g, rng());
}

vector<ull> fact(ull n){
    vector<ull> f;
    if(n == 1) f.push_back(1); //avoid RTE
    while(n != 1){
        if(isPrime(n)){
            f.push_back(n);
            n = 1;
        }else{
            ull cur = rho(n, rng());
            ull cf = 1;
            while(!(n % cur)){
                n /= cur;
                cf *= cur;
            }
            f.push_back(cf);
        }
    }
    sort(f.begin(),f.end());
    return f;
}

Mint dp[8192];
Mint p2[200005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    p2[0] = 1;
    for(int i=1;i<=200000;i++) p2[i] = p2[i-1] * 2;
    ll n, m;
    cin >> n >> m;
    Mint ans = 1;
    if(m == 1){
        for(int i=1;i<=n;i++){
            ll x;
            cin >> x;
            if(x == 1) ans *= 2;
        }
        cout << ans-1 << "\n";
    }else{
        auto fct = fact(m);
        int cn = fct.size();
        assert(cn <= 13);
        vector<int> ttc(1 << cn);
        for(int i=1;i<=n;i++){
            ll x;
            cin >> x;
            if(m % x == 0){
                int cm = 0;
                for(int j=0;j<fct.size();j++){
                    if(x % fct[j] == 0){
                        cm |= (1 << j);
                    }
                }
                ttc[cm]++;
            }
        }
        dp[0] = p2[ttc[0]];
        for(int i=1;i<(1 << cn);i++){
            for(int j=(1 << cn)-1;j>=0;j--){
                dp[j | i] += dp[j] * (p2[ttc[i]] - 1);
            }
        }
        cout << dp[(1 << cn) - 1] << "\n";
    }
}   
