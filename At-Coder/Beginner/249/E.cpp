#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll MOD = 3; 

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

const int N = 3005;
Mint dp[N][N]; //dp[k][x] sum k using total x digits
Mint sum[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n >> MOD;
    dp[0][0] = 1;
    sum[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            //dp[i][j] = sum dp[i-1][j-2] + dp[i-2][j-2] + ... + dp[i-9][j-2]; 
            //dp[i][j] += sum dp[i-10][j-3] + .... dp[i-99][j-3];
            if(i <= 9){
                if(j > 2) dp[i][j] += 25*sum[j-2][i-1];
                else if(j == 2) dp[i][j] += 26*sum[j-2][i-1];
            }else if(i <= 99){
                if(j > 2) dp[i][j] += 25*(sum[j-2][i-1] - sum[j-2][i-10]);
                else if(j == 2)  dp[i][j] += 26*(sum[j-2][i-1] - sum[j-2][i-10]);
                if(j > 3) dp[i][j] += 25*sum[j-3][i-10];
                else if(j == 3) dp[i][j] += 26*sum[j-3][i-10];
            }else if(i <= 999){
                if(j > 2) dp[i][j] += 25*(sum[j-2][i-1] - sum[j-2][i-10]);
                else if(j == 2)  dp[i][j] += 26*(sum[j-2][i-1] - sum[j-2][i-10]);
                if(j > 3) dp[i][j] += 25*(sum[j-3][i-10] - sum[j-3][i-100]);
                else if(j == 3) dp[i][j] += 26*(sum[j-3][i-10] - sum[j-3][i-100]);
                if(j > 4) dp[i][j] += 25*sum[j-4][i-100];
                else if(j == 4) dp[i][j] += 26*sum[j-4][i-100];
            }else{
                if(j > 2) dp[i][j] += 25*(sum[j-2][i-1] - sum[j-2][i-10]);
                else if(j == 2)  dp[i][j] += 26*(sum[j-2][i-1] - sum[j-2][i-10]);
                if(j > 3) dp[i][j] += 25*(sum[j-3][i-10] - sum[j-3][i-100]);
                else if(j == 3) dp[i][j] += 26*(sum[j-3][i-10] - sum[j-3][i-100]);
                if(j > 4) dp[i][j] += 25*(sum[j-4][i-100] - sum[j-4][i-1000]);
                else if(j == 4) dp[i][j] += 26*(sum[j-4][i-100] - sum[j-4][i-1000]);
                if(j > 5) dp[i][j] += 25*sum[j-5][i-1000];
                else if(j == 5) dp[i][j] += 26*sum[j-5][i-1000];
            }
            sum[j][i] = sum[j][i-1] + dp[i][j];
        }
    }
    Mint ans = 0;
    for(int j=0;j<n;j++) ans += dp[n][j];
    cout << ans << "\n";
}
