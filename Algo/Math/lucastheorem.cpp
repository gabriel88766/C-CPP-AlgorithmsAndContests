#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;//1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int MOD;
// template <int MOD_val=998244353>
struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
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
    Mint& operator*= (const Mint &u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint& operator+= (const Mint &u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint& operator-= (const Mint &u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint& operator/= (const Mint &u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint &u) const { return v == u.v;}
    bool operator!= (const Mint &u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 1e6+1;
Mint fat[N], invfat[N];
void init_lucas(int p){
    MOD = p;
    fat[0] = 1;
    for(int i=1;i<p;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[p-1] = 1/fat[p-1];
    for(int i=p-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}

Mint nCr_lucas(int a, int b){
    if(a < b) return 0;
    return fat[a] * invfat[b] * invfat[a-b];
}

Mint lucas(ll n, ll m){
    Mint ans = 1;
    while(n || m){
        ans *= nCr_lucas(n % MOD, m % MOD);
        n /= MOD;
        m /= MOD;
    }
    return ans;
}

