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

const int N = 1e5+3;
int v[N];
int ps[N][51];
Mint dp[8][64];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
         cin >> v[i];
         for(int j=0;j<=50;j++) ps[i][j] = ps[i-1][j];
         ps[i][v[i]]++;
    }
    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        if(ps[r][0] - ps[l-1][0] >= 1){
            cout << r-l << " " << ps[r][0] - ps[l-1][0] << "\n";
        }else{
            Mint qt = 0;
            bool ok = false;
            for(int i=1;i<=50;i++){
                ll aux = ps[r][i] - ps[l-1][i];
                if(aux >= 2) ok = true;
                qt += (aux * (aux - 1))/2;
            }
            if(ok) cout << r - l - 1 << " " << qt << "\n";
            else{
                // r - l + 1 <= 50 dp O(64*50*7)
                assert(r-l+1 <= 50);
                for(int l=0;l<64;l++){
                    for(int j=0;j<=7;j++){
                        dp[j][l] = 0;
                    }
                }
                dp[0][0] = 1;
                int mn = 7;
                bool ok = false;
                for(int i=l;i<=r;i++){
                    for(int j=mn;j>=1;j--){
                        for(int u=63;u>=0;u--){
                            dp[j][u] += dp[j-1][u^v[i]];
                        }
                        if(dp[j][0] != 0){
                            mn = j;
                            ok = true;
                        }
                    }
                }
                if(ok){
                    cout << r-l+1-mn << " " << dp[mn][0] << "\n";
                }else cout << "-1\n";
            }
        }
    }
}
