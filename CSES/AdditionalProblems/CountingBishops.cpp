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

Mint dpe[505][505];
Mint dpo[505][505];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    dpe[0][0] = dpo[0][0] = 1;
    for(int i=1;2*i-1<n;i++){
        int w = 2*i-1;
        for(int j=0;j<=2*i-1;j++){
            dpo[i][j] += dpo[i-1][j];
            dpo[i][j+1] += dpo[i-1][j] * Mint(w-j) * 2;
            dpo[i][j+2] += dpo[i-1][j] * (Mint(w-j) * Mint(w-j-1));
        }
    }
    for(int i=1;2*i<n;i++){
        int w = 2*i;
        for(int j=0;j<=2*i;j++){
            dpe[i][j] += dpe[i-1][j];
            dpe[i][j+1] += dpe[i-1][j] * Mint(w-j) * 2;
            dpe[i][j+2] += dpe[i-1][j] * (Mint(w-j) * Mint(w-j-1));
        }   
    }
    
    int x, y;
    if(n % 2){
        x = (n+1)/2;
        y = n/2;
        for(int j=0;j<=n;j++){
            dpo[x][j] += dpo[x-1][j];
            dpo[x][j+1] += dpo[x-1][j] * Mint(n-j);
        }
    }else{
        x = n/2;
        y = n/2;
        for(int j=0;j<=n;j++){
            dpe[y][j] += dpe[y-1][j];
            dpe[y][j+1] += dpe[y-1][j] * Mint(n-j);
        }
    }
    Mint ans = 0;
    for(int i=0;i<=k;i++){
        if(i <= 500 && k-i <= 500){
            ans += dpo[x][i] * dpe[y][k-i];
        }
    }
    cout << ans << "\n";
}
