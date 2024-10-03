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

Mint p;
Mint dps[2][5005];
Mint E[5005];
//E((x*(x-1)*(x-2)*...(x-k+1))) = p^k * n * (n-1) * ... (n-k+1) make the dp..
Mint solvet(int n, int k){
    dps[1][1] = 1; //E(x)k =>  (easy to calc??) maybe not
    Mint fn = n;
    Mint pf = p;
    E[1] = fn * pf;
    int lm = 0;
    for(int i=2;i<=k;i++){
        lm--;
        fn *= (n + lm);
        pf = p * pf;
        Mint Exi = fn * pf;
        int b = i % 2;
        for(int j=1;j<=i;j++){
            dps[b][j] = dps[b^1][j-1]; //multiply by x
            dps[b][j] += dps[b^1][j] * lm; //multiply by -i+1
        }
        //Exi = sum E[j] * dps[b][j] from j = 1 to i => E[i] = Exi - sum E[j] * dps[b][j] from j = 1 to i-1
        for(int j=1;j<i;j++){
            E[i] -= E[j] * dps[b][j];   
        }
        E[i] += Exi;
    }
    return E[k];
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    p = Mint(1)/m;
    cout << solvet(n, k) << "\n";
}
