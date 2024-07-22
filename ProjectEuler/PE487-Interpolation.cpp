#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

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

ll MOD;
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

//condition: f(0) = y[0], f(1) = y[1], .... f(n) = y[n];
// n+1 points => degree n
Mint interp(vector<Mint> &y, ll x){
    Mint ans = 0;
    Mint P = 1;
    vector<Mint> fat(y.size());
    fat[0] = 1;
    for(int i=0;i<y.size();i++){
        P *= (x - i);
        if(i != 0) fat[i] = fat[i-1]*i;
    }
    for(int i=0;i<y.size();i++){
        Mint coef = P / (x-i);//log M
        //coef /= prod  (xi - xj) for j != i = prod (xi - j) for j = 0 to y.size()-1 = i! * (j-i)! * (-1)^j
        int d = y.size() - 1 - i;
        coef /= (fat[i] * fat[d] * (d % 2 ? -1 : 1));
        ans += y[i] * coef;
    }
    return ans;
}

const int POT = 10000;
const ll N = 1'000'000'000'000LL;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<ll> pr;
    for(ll p=2'000'000'000; p<= 2'000'002'000; p++){
        if(isPrime(p)) pr.push_back(p);
    }
    ll ans = 0;
    for(auto x : pr){
        MOD = x;
        vector<Mint> v = {0};
        vector<Mint> v2 = {0};
        for(int i=1;i<=POT+2;i++){
            v.push_back(v.back() + Mint(i).pow(POT));
            v2.push_back(v.back() + v2.back());
        }
        ans += interp(v2, N).v;
    }
    cout << ans << "\n";
}
