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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<Mint> dp(n+1);
    vector<vector<Mint>> dp2(n+1, vector<Mint>(n+1, 0));
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        //from 1 to i;
        if(v[i] == -1){
            dp[i] = dp[i-1] * n;
            for(int j=1;j<=n;j++) dp2[i][j] = dp[i-1];
            bool ok = true;
            int val = -1;
            for(int j=1;j<i;j++){
                if(v[i-j] != -1){
                    ok = false;
                    if(val == -1) val = v[i-j];
                    else if(val != v[i-j]) break;
                }   
                if(ok || val == j){
                    Mint qt = dp[i-j-1] - dp2[i-j-1][j];
                    dp[i] -= qt;
                    dp2[i][j] -= qt;
                }
            }
        }else{
            dp[i] = dp[i-1];
            dp2[i][v[i]] = dp[i-1];
            if(v[i] < i){
                bool ok = true;
                for(int j=i-v[i];j<=i;j++){
                    if(v[j] != -1 && v[j] != v[i]) ok = false;
                }
                if(ok){
                    Mint qt = dp[i-v[i]-1] - dp2[i-v[i]-1][v[i]];
                    dp[i] -= qt;
                    dp2[i][v[i]] -= qt;
                }
            }
        }
    }
    cout << dp[n] << "\n";
}
