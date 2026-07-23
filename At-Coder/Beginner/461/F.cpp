#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
        if(u < 0) return (Mint(1)/v).pow(-u);
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

Mint dp[5000][15], dp2[5000][15];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    vector<ll> divs;
    for(ll i = 1; i*i <= n; i++){
        if(n % i == 0){
            divs.push_back(i);
            if(i * i != n) divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    assert(divs.size() <= 2500 && divs.size() >= 1);
    assert(divs[0] == 1);
    dp[divs.size() - 1][0] = 1; //however the sum is 0! :)
    int m = divs.size();
    //solve
    for(auto d : divs){
        for(int j=12;j>=0;j--){
            int p = 0;
            for(int i = 0; i < m; i++){
                while(divs[p] * d < divs[i]) p++;
                if(divs[p] * d != divs[i]) continue;
                dp[p][j+1] += dp[i][j];
                dp2[p][j+1] += dp[i][j] * d + dp2[i][j];
            }
        }
    }

    Mint ans = 0;
    Mint aux = 1;
    for(int i=1;i<=13;i++){
        aux *= i;
        ans += aux * dp2[0][i];
    }
    cout << ans << "\n";
}
