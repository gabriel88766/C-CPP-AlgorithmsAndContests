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

const int N = 10005;

Mint dp[2][N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, x;
    cin >> n >> x;
    Mint inv = Mint(1)/n;
    vector<ll> t(n);
    for(int i=0;i<n;i++) cin >> t[i];
    Mint ans = 0;
    dp[0][t[0]] = inv;
    for(int j=1;j<n;j++) dp[1][t[j]] += inv;
    for(int i=1;i<=x;i++){
        for(int j=1;j<N;j++){
            if(j != 1){
                dp[1][j-1] = dp[1][j];
                dp[0][j-1] = dp[0][j];
            }else dp[0][j-1] = dp[0][j] + dp[1][j];
        }
        dp[0][t[0]] = dp[0][0] * inv;
        for(int j=1;j<n;j++) dp[1][t[j]] += dp[0][0] * inv;
    }
    for(int i=1;i<=t[0];i++) ans += dp[0][i];
    cout << ans << "\n";
}
