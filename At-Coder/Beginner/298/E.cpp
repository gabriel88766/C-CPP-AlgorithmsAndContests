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

Mint dp1[101][101], dp2[101][101];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    dp1[0][0] = dp2[0][0] = 1;
    int g = n - a;
    for(int i=1;i<=100;i++){
        for(int j=0;j<g;j++){
            for(int k=1;k<=p;k++){
                dp1[i][min(j+k, g)] += dp1[i-1][j];
            }
        }
    }
    g = n - b;
    for(int i=1;i<=100;i++){
        for(int j=0;j<g;j++){
            for(int k=1;k<=q;k++){
                dp2[i][min(j+k, g)] += dp2[i-1][j];
            }
        }
    }
    Mint ans = 0;
    for(int i=1;i<=100;i++){
        Mint pa = dp1[i][n-a]/Mint(p).pow(i);
        Mint pb = 0;
        for(int j=i;j<=100;j++){
            pb += dp2[j][n-b]/Mint(q).pow(j);
        }
        ans += pa*pb;
    }
    cout << ans;

}
