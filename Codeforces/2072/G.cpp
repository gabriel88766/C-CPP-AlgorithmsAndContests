#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
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

Mint rev2 = Mint(1)/2;
Mint rev6 = Mint(1)/6;

Mint ssq(ll n){
    Mint ans = n;
    ans *= (n+1);
    ans *= (2*n+1);
    ans *= rev6;
    return ans;
}

Mint ss(ll n){
    Mint ans = n;
    ans *= n+1;
    ans *= rev2;
    return ans;
}

Mint calc(ll a, ll b, ll k, ll m){
    Mint ans = Mint(a) * Mint(b) * Mint(m+1);
    ans += ss(m) * a;
    ans -= ss(m) * Mint(k) * Mint(b);
    ans -= Mint(k) * ssq(m);
    return ans;
}

int pws[300005][20];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=2;i<=300000;i++){
        ll px = 1;
        pws[i][0] = px;
        for(int j=1;j<20;j++){
            if(px * i > INF_INT) px = INF_INT;
            else px = px * i;
            pws[i][j] = px;
        }
    }
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll p = 2;
        Mint ans = 0;
        while(p <= k){
            if(p > n){
                ans += Mint(k-p+1) * n;
                p = k+1;
            }else if(p*p > n){
                ll dv = n / p;
                ll mx = n / dv;
                mx = min(mx, k);
                ans += calc(n % p, p, dv, mx - p);
                ans += Mint(mx - p + 1) * dv;
                p = mx + 1;
            }else{
                int fp = 1;
                int pot = 0;
                while(fp * p <= n){
                    fp *= p;
                    pot++;
                }
                int aux = n;
                for(int j=pot;j>=0;j--){
                    ans += Mint(pws[p][pot-j]) * Mint(aux / pws[p][j]);
                    aux -= (aux/pws[p][j])*pws[p][j];
                }
                p++;
            }
        }
        cout << ans << "\n";
    }
}
