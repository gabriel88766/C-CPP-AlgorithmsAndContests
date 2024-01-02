#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
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

int dp1[5005][5005];
vector<vector<Mint>> dp(2, vector<Mint>(5005));
Mint aux[5005], dp2[5005];
void init(){
    dp1[0][0] = 1;
    for(int i=1;i<=5000;i++){
        for(int j=0;j<=i;j++){
            if(j) dp1[i][j] = (dp1[i][j] + (2*dp1[i-1][j-1]) % MOD) % MOD;
            dp1[i][j] = (dp1[i][j] + dp1[i-1][j+1]) % MOD;
        }
    }
    for(int i=2;i<=5000;i+=2){
        aux[i] = dp1[i-2][0];
    }
    dp2[0] = 1;
    dp2[2] = aux[2];
    for(int i=4;i<=5000;i+=2){
        dp2[i] = aux[i];
        for(int j=2;j<i;j+=2){
            dp2[i] += aux[j] * dp2[i-j];
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    ll n;
    string s;
    cin >> n >> s;
    int m = s.size();
    dp[0] = 0;
    Mint ans = 0;
    for(int i=1;i<=n;i++){
        for(int k=0;k<=m;k++){
            //optimize ↓
            /*for(int j=i-2;j>=0;j-=2){
                dp[i][k] += dp[j][k] * dp2[i-j-2][0];
                if(k == m) dp[i][k] += dp[j][k] * dp2[i-j-2][0];
            }*/
            if(k == 0) dp[i][k] += dp[i-1][k] + dp[i-1][k+1];
            else if(k == m) dp[i][k] += dp[i-1][k-1];
            else dp[i][k] += dp[i-1][k-1] + dp[i-1][k+1];
        }
    }
    cout << ans << "\n";
}
