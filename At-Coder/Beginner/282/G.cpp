#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
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

Mint dp[2][101][101][101];
Mint aux[101][101], aux2[101][101], aux3[101][101], aux4[101][101];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k >> MOD;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1;j++){
            dp[1][0][i][j] = 1; //quantity of numbers greater than A1, and B1
        }
    }
    for(int xx=2;xx<=n;xx++){
        int b = xx & 1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    dp[b][i][j][k] = 0;
                }
            }
        }
        for(int u=0;u<=xx-2;u++){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    aux[i][j] = 0;
                    aux2[i][j] = 0;
                    aux3[i][j] = 0;
                    aux4[i][j] = 0;
                }
            }
            for(int i=0;i<=n-xx+1;i++){
                for(int j=0;j<=n-xx+1;j++){
                    if(i >= 1 && j >= 1){ //go to greater
                        aux[i-1][j-1] += dp[b^1][u][i][j];
                    } 
                    if(i <= n-xx && j <= n - xx){ //go to lower
                        aux2[i][j] += dp[b^1][u][i][j];
                    }
                    //now the go to low up or up low
                    if(i >= 1 && j <= n-xx){
                        aux3[i-1][j] += dp[b^1][u][i][j];
                    }
                    if(i <= n-xx && j >= 1){
                        aux4[i][j-1] += dp[b^1][u][i][j];
                    }
                }
            }
            for(int i=n-xx;i>=0;i--){
                for(int j=n-xx;j>=0;j--){
                    aux[i][j] += aux[i+1][j] + aux[i][j+1] - aux[i+1][j+1];
                    dp[b][u+1][i][j] += aux[i][j];
                }
            }
            for(int i=0;i<=n-xx;i++){
                for(int j=0;j<=n-xx;j++){
                    if(i > 0 && j > 0) aux2[i][j] += aux2[i-1][j] + aux2[i][j-1] - aux2[i-1][j-1];
                    else if(i > 0) aux2[i][j] += aux2[i-1][j];
                    else if(j > 0) aux2[i][j] += aux2[i][j-1];
                    dp[b][u+1][i][j] += aux2[i][j];
                }
            }
            for(int i=n-xx;i>=0;i--){
                for(int j=0;j<=n-xx;j++){
                    if(j > 0) aux3[i][j] += aux3[i+1][j] + aux3[i][j-1] - aux3[i+1][j-1];
                    else aux3[i][j] += aux3[i+1][j];
                    dp[b][u][i][j] += aux3[i][j];
                }
            }
            for(int i=0;i<=n-xx;i++){
                for(int j=n-xx;j>=0;j--){
                    if(i > 0) aux4[i][j] += aux4[i][j+1] + aux4[i-1][j] - aux4[i-1][j+1];
                    else aux4[i][j] += aux4[i][j+1];
                    dp[b][u][i][j] += aux4[i][j];
                }
            }
        }
        
    }
    cout << dp[n & 1][k][0][0] << "\n";
}
