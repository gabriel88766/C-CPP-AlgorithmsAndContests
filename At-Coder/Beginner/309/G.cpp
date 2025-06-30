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
    ll gcd_euclid(ll a, ll b, ll &x, ll &y){ //solves ax+by = g where g = gcd(a,b)
        if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
            x = 1; y = 0;
            return a;
        }
        ll d = gcd_euclid(b, a % b, y, x); //if b > a then this step reverses it
        y -= x * (a/b); 
        return d;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    /*Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}*/
    Mint operator/= (Mint u){ //division , MOD not prime, u.v must be coprime with MOD.
        ll x, y;
        ll g = gcd_euclid(u.v, MOD, x, y);
        assert(g == 1);
        (*this) *= x; 
        return *this;
    }
    bool operator== (const Mint u) const { return v == u.v;}
    bool operator!= (const Mint u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 105;
Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
Mint nCr(ll a, ll b){
    assert(a >= b); //catch silly bugs
    return fat[a]*invfat[a-b]*invfat[b];
}

Mint dp[2][N][512];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, x;
    cin >> n >> x;
    int msk = 511;
    dp[0][0][0] = 1;
    const int mid = 4;//mid bit 
    for(int i=1;i<=n;i++){
        int b = i & 1;
        int ob = b ^ 1;
        for(int j=0;j<i;j++){
            for(int k=0;k<=msk;k++){
                dp[b][j][k] = 0;
            }
        }
        int pb = 0;
        for(int j=mid-min(i - 1, x - 1);j<=mid+min(n - i, x - 1);j++) pb |= (1 << j);
        for(int j=0;j<i;j++){
            for(int k=0;k<=msk;k++){
                int nm = (k >> 1) & msk;
                dp[b][j][nm] += dp[ob][j][k];
                for(int nb = 0; nb <= 8; nb++){
                    if(pb & (1 << nb) && (!(nm & (1 << nb)))){
                        dp[b][j+1][nm | (1 << nb)] += dp[ob][j][k];
                    }
                }
            }
        }
    }
    Mint ans = fat[n];
    for(int i=1;i<=n;i++){
        Mint cur = 0;
        for(int k=0;k<=msk;k++){
            cur += dp[n & 1][i][k];
        }
        // cout << cur << " ";
        // cout << "jo" << endl;
        if(i & 1){
            ans -= cur * fat[n - i];
        }else{
            ans += cur * fat[n - i];
        }
    }
    cout << ans << "\n";
}
