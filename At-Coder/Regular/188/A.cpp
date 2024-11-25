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
    Mint operator/= (Mint u){ //division , MOD not prime, u.v must be coprime with MOD.
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
int sum(int u){
    --u;
    int ans = u * (u+1);
    return ans / 2;
}
Mint dp[4][52][52][52][52]; //000 or 111 // 001 or 110 // 010 or 101 // 011 or 100
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, K;
    string s;
    cin >> n >> K >> s;
    s = " " + s;
    dp[0][1][0][0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k+j<=i;k++){
                for(int z=0;k+j+z<=i;z++){
                    //current is j, k, z, i-j-k-z
                    if(s[i] == 'A' || s[i] == '?'){
                        dp[3][j][k][z][i-j-k-z+1] += dp[0][j][k][z][i-j-k-z];
                        dp[2][j][k][z+1][i-j-k-z] += dp[1][j][k][z][i-j-k-z];
                        dp[1][j][k+1][z][i-j-k-z] += dp[2][j][k][z][i-j-k-z];
                        dp[0][j+1][k][z][i-j-k-z] += dp[3][j][k][z][i-j-k-z];
                    }
                    if(s[i] == 'B' || s[i] == '?'){
                        dp[2][j][k][z+1][i-j-k-z] += dp[0][j][k][z][i-j-k-z];
                        dp[3][j][k][z][i-j-k-z+1] += dp[1][j][k][z][i-j-k-z];
                        dp[0][j+1][k][z][i-j-k-z] += dp[2][j][k][z][i-j-k-z];
                        dp[1][j][k+1][z][i-j-k-z] += dp[3][j][k][z][i-j-k-z];
                    }
                    if(s[i] == 'C' || s[i] == '?'){
                        dp[1][j][k+1][z][i-j-k-z] += dp[0][j][k][z][i-j-k-z];
                        dp[0][j+1][k][z][i-j-k-z] += dp[1][j][k][z][i-j-k-z];
                        dp[3][j][k][z][i-j-k-z+1] += dp[2][j][k][z][i-j-k-z];
                        dp[2][j][k][z+1][i-j-k-z] += dp[3][j][k][z][i-j-k-z];
                    }
                }
            }
        }
    }
    Mint ans = 0;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j+i<=n+1;j++){
            for(int k=0;i+j+k<=n+1;k++){
                int z = n+1 - i - j - k;
                int tt = sum(i) + sum(j) + sum(k) + sum(z);
                if(tt < K) continue;
                Mint cur = 0;
                for(int u=0;u<=3;u++) cur += dp[u][i][j][k][z];
                ans += cur;
            }
        }
    }
    cout << ans << "\n";
}
