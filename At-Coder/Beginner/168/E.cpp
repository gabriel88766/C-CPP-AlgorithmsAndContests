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

struct Frac{
    ll a, b;
    Frac(ll a, ll b){
        if(b < 0) *this = Frac(-a, -b);
        else this->a = a, this->b = b;
    }
    bool operator< (const Frac &v) const{
        if(a != v.a) return a < v.a;
        else return b < v.b;
    }
};
const int N = 2e5+3;
map<Frac, bool> vis;
map<Frac, ll> mp;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    int a0 = 0, b0 = 0;
    Mint t2 = 0;
    for(int i=0;i<n;i++){
        ll a, b;
        cin >> a >> b;
        if(a == 0 && b == 0){
            t2+=1;
            continue;
        }
        if(a == 0 || b == 0){
            if(a == 0) a0++;
            if(b == 0) b0++;
            continue;
        }
        ll g = gcd(abs(a), abs(b));
        a /= g, b /= g;
        mp[{a, b}]++;
    }
    Mint ans = Mint(2).pow(a0) + Mint(2).pow(b0) - 1;
    for(auto [k, x] : mp){
        Frac inv = {-k.b, k.a};
        if(!vis[k]){
            vis[k] = true;
            Mint aux  = Mint(2).pow(x);
            if(mp.count(inv)){
                vis[inv] = true;
                aux += Mint(2).pow(mp[inv]);
                aux -= 1;
            }
            ans *= aux;
        }
    }
    ans -= 1;
    ans += t2;
    cout << ans << "\n";
}
