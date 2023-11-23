#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //
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

struct Matrix{
    Mint a00, a01, a10, a11;
    Matrix operator*= (const Matrix &m){
        Matrix cp = *this;
        a00 = cp.a00*m.a00 + cp.a01*m.a10;
        a01 = cp.a00*m.a01 + cp.a01*m.a11;
        a10 = cp.a10*m.a00 + cp.a11*m.a10;
        a11 = cp.a10*m.a01 + cp.a11*m.a11;
        return *this;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll A, B, n, x;
    cin >> A >> B >> n >> x;
    Mint t0 = x;
    Mint t1 = Mint(A) * Mint(t0) + Mint(B);
    n--;
    Matrix a;
    Matrix ans;
    a.a00 = A+1, a.a01 = -A, a.a10 = 1, a.a11 = 0;
    ans.a00 = 1, ans.a01 = 0, ans.a10 = 0, ans.a11 = 1;
    ll oldn = n;
    while(n){
        if(n & 1){
            ans *= a;
        }
        Matrix b = a;
        a *= b;
        n >>= 1;
    }
    if(oldn){
        cout << ans.a00 * t1 + ans.a01 * t0 << "\n";
    }else cout << t1 << "\n";
}