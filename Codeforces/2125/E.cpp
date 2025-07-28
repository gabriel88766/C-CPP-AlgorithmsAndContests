#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


struct Mint{
    int v;
    //static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(int u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
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
    Mint operator*= (Mint u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint u) const { return v == u.v;}
    bool operator!= (const Mint u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 4e5+3; //O(N) preprocessing, O(1) query

//Using Mint
Mint dp[N], ndp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input

    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        Mint ans = 0;
        ll sum = n;
        sum *= (n-1);
        sum /= 2;
        
        dp[0] = 1;
        ll mx = x - (n-1) - sum;
        for(ll i=1;i<=n-1;i++){
            for(ll j=0;j<=mx;j++){
                if(j >= i){
                    ndp[j] = ndp[j-i] + dp[j];
                }else{
                    ndp[j] = dp[j];
                }
            }
            for(ll j=0; j<=mx;j++){ 
                dp[j] = ndp[j];
            }
        }
        for(int j=1;j<=x;j++) dp[j] += dp[j-1];
        for(ll i=max(n+sum-1, 1LL);i<=x;i++){
            ll cur = i - n - sum + 1;
            if(cur >= 0) ans += dp[cur];
        }
        for(int i=0;i<=x;i++) dp[i] = ndp[i] = 0;
        cout << ans << "\n";
    }
}
