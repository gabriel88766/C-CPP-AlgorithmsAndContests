#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, k;
    cin >> n >> k >> MOD;
    Mint ans = 0;
    if(k % 2){
        for(int i=0;i<k;i++){
            int cgs = (2*i) % k;
            // i,  x|i
            // === k^n - (k-1)^n
            ans += Mint(k).pow(n-1) - Mint(k-1).pow(n-1);
            // ~i,  i
            vector<vector<Mint>> dp(n+1, vector<Mint>(k, 0));
            dp[0][0] = 1;
            for(int j=1;j<=n-1;j++){
                for(int x=0;x<k;x++){
                    for(int y=0;y<k;y++){
                        if(y == i) continue;
                        dp[j][(x+y)%k] += dp[j-1][x]; 
                    }
                }
            }
            ans += dp[n-1][i];
        }
    }else{
        for(int i=0;i<k/2;i++){
            int i1 = i, i2 = i+k/2;
            int cgs = (2*i) % k;
            //i1|i2,  x | i1 | i2
            ans += Mint(k).pow(n-1) - Mint(k-2).pow(n-1);
            //~i1&~i2, i1 | i2
            //sum i1 or i2 not using i1 nor i2
            vector<vector<Mint>> dp(n+1, vector<Mint>(k, 0));
            dp[0][0] = 1;
            for(int j=1;j<=n-1;j++){
                for(int x=0;x<k;x++){
                    for(int y=0;y<k;y++){
                        if(y == i1 || y == i2) continue;
                        dp[j][(x+y)%k] += dp[j-1][x]; 
                    }
                }
            }
            ans += dp[n-1][i1] + dp[n-1][i2];
        }
    }
    cout << ans << "\n";
}
