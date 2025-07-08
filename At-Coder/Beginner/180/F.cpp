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

const int N = 303;
Mint aux1[N], aux0[N];


//Using Mint
Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
Mint nCr(ll a, ll b){
    assert(a >= b); //catch silly bugs
    return fat[a]*invfat[a-b]*invfat[b];
}

Mint dp[N][N][2];


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n,m,l;
    cin >> n >>m>>l;
    init();
    aux1[2] = aux0[2] = aux1[1] = 1;
    for(int i=3;i<=l;i++){
        aux1[i] = fat[i] * invfat[2]; //path graph
        aux0[i] = fat[i-1] * invfat[2]; //cycle graph
    }
    dp[0][0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j > l) break;
            for(int k=0;k<=n;k++){
                if(j == l){
                    if(k >= 1) dp[i][k][1] += (dp[i-j][k-1][0] + dp[i-j][k-1][1]) * (j > 1 ? nCr(i-1, j-1) : 1) * aux1[j];
                    dp[i][k][1] += (dp[i-j][k][0] + dp[i-j][k][1]) * (j > 1 ? nCr(i-1, j-1) : 1) * aux0[j];
                }else{
                    if(k >= 1){
                        dp[i][k][1] += dp[i-j][k-1][1] * (j > 1 ? nCr(i-1, j-1) : 1) * aux1[j];
                        dp[i][k][0] += dp[i-j][k-1][0] * (j > 1 ? nCr(i-1, j-1) : 1) * aux1[j];   
                    }
                    dp[i][k][1] += dp[i-j][k][1] * (j > 1 ? nCr(i-1, j-1) : 1) * aux0[j];
                    dp[i][k][0] += dp[i-j][k][0] * (j > 1 ? nCr(i-1, j-1) : 1) * aux0[j];
                }
            }
        }
    }
    cout << dp[n][n-m][1] << "\n";



}   
