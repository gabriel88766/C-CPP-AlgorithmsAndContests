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


map<ll, Mint> dp;
map<ll, Mint> dp2;

Mint calc(ll n){
    if(dp.count(n)) return dp[n];
    ll m = (1+n) / 2;
    ll qt1 = m;
    ll qt2 = n - m;
    if(!dp.count(qt1)) dp[qt1] = calc(qt1);
    if(!dp.count(qt2)) dp[qt2] = calc(qt2);
    Mint ans = (Mint(2).pow(n) - Mint(2).pow(qt1) - Mint(2).pow(qt2)) + 1; // node 1
    dp2[n] = 2*dp2[qt1] + 2*dp2[qt2] + ans;
    ans += dp[qt1] + dp[qt2] + dp2[qt1] + 2*dp2[qt2];
    
    return dp[n] = ans;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[1] = 1;
    dp2[1] = 1;
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << calc(n) << "\n";
    }
}
