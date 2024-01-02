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

vector<vector<Mint>> dp(2, vector<Mint>(5005));

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1), ord(n+1);
    for(int i=1;i<=n;i++){
         cin >> v[i];
         ord[v[i]] = i;
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++) dp[1][j] = 0;
        Mint cur = 0;
        int cnt = 0;
        for(int j=i+1;j<=n;j++) if(ord[j] < ord[i]) cnt++;
        cnt += i;
        cur = dp[0][i-1];
        for(int j=i;j<=n;j++){
            dp[1][j] += cur;
            if(j >= cnt) dp[1][j] += dp[0][j];
            cur += dp[0][j];
        }
        for(int j=1;j<=n;j++) cout << dp[1][j] << " ";
        cout << "\n";
        dp[0] = dp[1];
    }
    cout << dp[1][n] << "\n";
}

//Unsolved!!!