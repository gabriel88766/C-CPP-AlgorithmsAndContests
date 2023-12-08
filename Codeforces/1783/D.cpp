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

const int N = 180700;

vector<vector<Mint>> dp(2, vector<Mint>(N));
vector<Mint> nullv(N);
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    const int zr = 90301;
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];

    dp[0][v[2]+zr] = 1;
    for(int i=2;i<=n-1;i++){
        for(int j=-90000;j<=90000;j++){
            if(j){
                dp[1][v[i+1]+zr-j] += dp[0][j+zr];
                dp[1][v[i+1]+zr+j] += dp[0][j+zr];
            }else{
                dp[1][v[i+1]+zr] += dp[0][j+zr];
            }
        }
        dp[0] = dp[1];
        dp[1] = nullv;
    }
    Mint ans = 0;
    for(int j=-90000;j<=90000;j++){
        ans += dp[0][zr+j];
    }
    cout << ans << "\n";
}
