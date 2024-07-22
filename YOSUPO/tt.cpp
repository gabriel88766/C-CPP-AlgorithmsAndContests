#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 8'000'000'000'000'000'000LL;
const int INF_INT = 0x3f3f3f3f;
const double PI = acos(-1.), EPS = 1e-9; 
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

//values P(0), P(1), P(2), ..., P(n), n degree
//if not like this, change the code.
vector<Mint> interp(vector<Mint> &x, vector<Mint> &y){
    Mint den
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    //freopen("out2", "w", stdout); //test input
    ll minv = 2'000'000'000;
    vector<ll> pr;
    for(ll i = minv; i <= minv+2000;i++){
        if(isPrime(i)) pr.push_back(i);
    }
    ll ans = 0;
    const ll e = 4;
    for(auto xp : pr){
        MOD = xp;
        //solve!
        vector<Mint> y, x;
        y.push_back(0);
        x.push_back(0);
        for(int i=1;i<=e+1;i++){
            y.push_back(Mint(i).pow(e) + y[i-1]);
            x.push_back(i);
        }
        //Lagrange now, e+2 points, polynomial degree e+1 
        auto ans = interp(x, y);
    }

}
