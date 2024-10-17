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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll x, y, z;
        cin >> x >> y >> z;
        if(z < max(x, y)) cout << "0\n";
        else if(z > max(x, y) + 1) cout << "0\n";
        else{
            if(x > y) swap(x, y);
            //x + y has y digits or y+1 digits
            if(x < y){
                Mint a0, a1, tt;
                Mint h = (Mint(10).pow(x) - Mint(10).pow(x-1));
                Mint b1 = Mint(10).pow(y) - Mint(10).pow(x) - Mint(10).pow(y-1) + 1;
                Mint b2 = Mint(10).pow(y) - Mint(10).pow(x-1) - Mint(10).pow(y-1);
                tt = (Mint(10).pow(y) - Mint(10).pow(y-1)) * h;
                a0 = h * (b1 + b2) / 2;
                a1 = tt - a0;
                if(z == y+1) cout << a1 << "\n";
                else cout << a0 << "\n";
            }else{
                //x == y
                Mint tt = (Mint(10).pow(x) - Mint(10).pow(x-1)).pow(2);
                Mint a0 = (Mint(10).pow(x) - 2*Mint(10).pow(x-1)) * (Mint(10).pow(x) - 2*Mint(10).pow(x-1) + 1);
                a0 /= 2;
                if(z == x) cout << a0 << "\n";
                else cout << tt - a0 << "\n";
            }
        }
    }
}
