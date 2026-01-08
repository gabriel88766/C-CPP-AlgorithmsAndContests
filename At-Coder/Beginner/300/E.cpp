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
    Mint(ll u){ 
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

Mint dp[64][64][64];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int a = 0, b = 0, c = 0;
    ll n;
    cin >> n;
    while(n % 2 == 0){
        n /= 2;
        a++;
    }
    while(n % 3 == 0){
        n /= 3;
        b++;
    }
    while(n % 5 == 0){
        n /= 5;
        c++;
    }
    if(n != 1){
        cout << "0\n";
        return 0;
    }
    dp[0][0][0] = 1;
    Mint inv = Mint(1)/5;
    vector<tuple<int, int, int>> vt;
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            for(int k=0;k<=c;k++){
                vt.push_back({i, j, k});
            }
        }
    }
    sort(vt.begin(), vt.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b){
        auto [a1,b1,c1] = a;
        auto [a2,b2,c2] = b;
        return a1+b1+c1 < a2+b2+c2;
    });
    for(auto [i, j, k] : vt){
        if(i < a){//2
            dp[i+1][j][k] += dp[i][j][k] * inv;
        }
        if(j < b){//3
            dp[i][j+1][k] += dp[i][j][k] * inv;
        }
        if(i + 2 <= a){
            dp[i+2][j][k] += dp[i][j][k] * inv;
        }
        if(k < c){
            dp[i][j][k+1] += dp[i][j][k] * inv;
        }
        if(i < a && j < b){
            dp[i+1][j+1][k] += dp[i][j][k] * inv;
        }
    }
    cout << dp[a][b][c] << "\n";
}
