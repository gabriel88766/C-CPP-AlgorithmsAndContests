#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(int u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
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
    Mint& operator*= (const Mint &u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint& operator+= (const Mint &u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint& operator-= (const Mint &u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint& operator/= (const Mint &u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint &u) const { return v == u.v;}
    bool operator!= (const Mint &u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 5005;
Mint dp[N][N];
int a[N], b[N], psa[N], psb[N];
bool rm[N][N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, l, r;
    cin >> n >> l >> r;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        psa[i] = a[i] + psa[i-1];
    }
    for(int i=1;i<=n;i++){
         cin >> b[i];
         psb[i] = psb[i-1] + b[i];
    }
    auto calc = [&](){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=i;j++){
                dp[i][j] = 0;
            }
        }
        if(!rm[0][0]) dp[0][0] = 1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=i;j++){
                if(rm[i][j]) continue;
                if(i != 0) dp[i][j] += dp[i-1][j];
                if(j != 0) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[n][n];
    };
    vector<pair<int, int>> rm1, rm2;
    int sum = psb[n] - psa[n];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(sum - psb[j] + psa[i] > r) rm1.push_back({i, j});
            else if(sum - psb[j] + psa[i] >= l) rm2.push_back({i, j});
        }
    }
    Mint ans = 0;
    for(auto [a, b] : rm1) rm[a][b] = true;
    ans = calc();
    for(auto [a, b]: rm2) rm[a][b] = true;
    ans -= calc();
    cout << ans << "\n";

}
