#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    ll v;
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
    int n, k;
    cin >> n >> k;
    vector<vector<vector<Mint>>> dp(n+1, vector<vector<Mint>> (n/k+2, vector<Mint> (k, 0)));
    dp[0][0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n/k;j++){
            Mint S = 0;
            for(int w=k-1;w>=0;w--){
                if(w == k-1){
                    dp[i][j+1][0] += dp[i-1][j][w];
                }else{
                    dp[i][j][w+1] += (k-w)*dp[i-1][j][w];
                }
                S += dp[i-1][j][w];
                if(w != 0) dp[i][j][w] += S;
            }
        }
    }
    Mint ans = 0;
    for(int i=1;i<=n/k+1;i++){
        for(int j=0;j<k;j++){
            ans += dp[n][i][j]*i;
        }
    }
    cout << ans << "\n";
}
