#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
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



Mint fat[21], invfat[21];
void init(){ //MOD must be prime
    fat[0] = invfat[20] = 1;
    for(int i=1;i<21;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[20] = 1/fat[20];
    for(int i=19;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
Mint nCr(ll a, ll b){
    if(b > a || b < 0 || a < 0) return 0;
    assert(a >= b); //catch silly bugs
    return fat[a]*invfat[a-b]*invfat[b];
}
vector<char> dg = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
Mint dp[3][17], ndp[3][17];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input


    init();
    string s;
    int k;
    cin >> s >> k;
    int msk = 0;
    Mint ans = 0;
    int n = s.size();
    dp[0][0] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=16;j++){
            //dp[0][j] has j digits, none is 0
            //dp[1][j] has j digits, first is 0
            //dp[2][j] has j digits, 0 among them, first isn't 0
            ndp[0][j] += dp[0][j] * j; //keep j
            ndp[0][j+1] += dp[0][j] * (15 - j);
            ndp[1][j+1] += dp[0][j];

            ndp[1][j] += dp[1][j] + dp[2][j]; //another 0;
            ndp[2][j] += (dp[1][j] + dp[2][j]) * (j - 1);
            ndp[2][j+1] += (dp[1][j] + dp[2][j]) * (16 - j);
        }
        for(int j=0;j<=16;j++){
            for(int x=0;x<=2;x++){
                dp[x][j] = ndp[x][j];
                ndp[x][j] = 0;
                if(x != 1 && j == k) ans += dp[x][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=15;j++){
            if(dg[j] == s[i]) break;
            if(i == 0 && j == 0) continue;
            int cmsk = __builtin_popcount(msk | (1 << j));

            if(k >= cmsk && i != n-1){
                Mint sn = 1;
                for(int x=k;x>=cmsk;x--){
                    ans += sn * nCr(16 - cmsk, k - cmsk) * Mint(x).pow(n-i-1) * nCr(k - cmsk, x - cmsk);
                    sn *= -1;
                }
            }else if(k == cmsk && i == n-1) ans += 1;
        }
        for(int j=0;j<=15;j++){
            if(dg[j] == s[i]) msk |= (1 << j);
        }
    }

    if(__builtin_popcount(msk) == k) ans += 1;
    cout << ans << "\n";
}
