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

vector<vector<vector<Mint>>> dp(2, vector<vector<Mint>>(1 << 10, vector<Mint>(10)));
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    int n;
    cin >> n >> s;
    for(int i=0;i<n;i++){
        int st = i % 2;
        int os = st ^ 1;
        int cl = s[i] - 'A';
        for(int j=0;j<(1 << 10); j++) for(int k=0;k<10;k++) dp[st][j][k] = dp[os][j][k];
        for(int j=0;j<(1 << 10); j++){
            if((1 << cl) & j){
                if(__builtin_popcount(j) == 1){
                    dp[st][j][cl] += 1;
                }
                for(int k=0;k<10;k++) if(k != cl) dp[st][j][cl] += dp[os][j ^ (1 << cl)][k];
                dp[st][j][cl] += dp[os][j][cl];
            }//else = 0
        }
    }
    Mint ans = 0;
    int st = (n - 1) % 2;
    for(int j=0;j<(1 << 10);j++){
        for(int k=0;k<10;k++){
            ans += dp[st][j][k];
        }
    }
    cout << ans << "\n";
}
