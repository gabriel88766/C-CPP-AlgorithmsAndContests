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
    Mint operator/= (Mint u){ //division untested, MOD not prime, u.v must be coprime with MOD.
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

Mint dp[1005][2005][4];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[1][1][0] = dp[1][1][3] = 1;
    dp[1][2][1] = dp[1][2][2] = 1;
    int n, k;
    cin >> n >> k;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=2*n;j++){//0 W W, 1 B W, 2 W B, 3 B B.
            dp[i][j][0] += dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j][0];
            dp[i][j+1][0] += dp[i-1][j][3];
            dp[i][j][1] += dp[i-1][j][1];
            dp[i][j+1][1] += dp[i-1][j][0] + dp[i-1][j][3];
            dp[i][j+2][1] += dp[i-1][j][2];
            dp[i][j][2] += dp[i-1][j][2];
            dp[i][j+1][2] += dp[i-1][j][0] + dp[i-1][j][3];
            dp[i][j+2][2] += dp[i-1][j][1];
            dp[i][j][3] += dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j][3];
            dp[i][j+1][3] += dp[i-1][j][0];
        }
    }
    cout << dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3] << "\n";
}
