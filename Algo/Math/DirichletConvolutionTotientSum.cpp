#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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

//sf(n)  =  (s(f conv g)(n) - sum[i=2:n](sf(n/i) * g(i))) /g(1)
//example f(i) = phi(i), phi conv I = Id, sum Id is easy to calculate, sum of I is too
unordered_map<ll, Mint> dp;
Mint inv = Mint(1)/2;
Mint calcconv(ll n){
    //something easy to calculate
    return Mint(n)*Mint(n+1) * inv;
}

ll ctt =0 ;
Mint calcsum(ll n){
    if(dp.count(n)) return dp[n];
    Mint ans = calcconv(n);
    //ll g1 = 1; //ignore in this case
    ll fv = 2;
    for(ll i=2;i*i<=n;i++){
        if(!dp.count(n/i)) calcsum(n/i);
        ans -= dp[n/i]; 
        fv = i+1;
    }
    while(fv <= n){
        ll lv = n/(n / fv);
        //sum of g from fv to lv . In this case = lv - fv + 1
        if(!dp.count(n/lv)) calcsum(n/lv);
        ans -= Mint(lv - fv + 1) * dp[n/lv]; 
        fv = lv+1;
    }
    //g(i) = 1, no need to divide
    return dp[n] = ans;
}


//precompute up to n^(2/3)
const int N = 10e6; //2*10^7, for 10^11
int phi[N];
void euler(){
    for(ll i=1;i<N;i++) phi[i] = i;
    for(ll i=2; i < N; i++){
        if(phi[i] == i){
            for(ll j = i; j < N; j += i){
                phi[j] -= phi[j]/i; 
            }
        }
    }
    dp[1] = 1;
    for(int i=2;i<N;i++){
        dp[i] = dp[i-1] + phi[i];
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    euler();
    ll n;
    cin >> n;
    cout << calcsum(n) << "\n";
}
