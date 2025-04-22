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

const int N = 2005;
char gr[N][N];
Mint dp1[N][N], dp2[N][N], ps[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, d;
        cin >> n >> m >> d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> gr[i][j];
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++) ps[j] = ps[j-1] + dp1[i+1][j] + dp2[i+1][j];
            for(int j=1;j<=m;j++){
                Mint val;
                if(i == n) val = 1;
                else val = ps[min(j+d-1, m)] - ps[max(j-d, 0)];
                if(gr[i][j] == 'X') dp1[i][j] = val;
                else dp1[i][j] = 0;
            }
            for(int j=1;j<=m;j++) ps[j] = ps[j-1] + dp1[i][j];
            for(int j=1;j<=m;j++){
                Mint val;
                val = ps[min(j+d, m)] - ps[max(j-d-1, 0)] - dp1[i][j];
                if(gr[i][j] == 'X') dp2[i][j] = val;
                else dp2[i][j] = 0;
            }
        }
        Mint ans = 0;
        for(int j=1;j<=m;j++) ans += dp1[1][j] + dp2[1][j];
        cout << ans << "\n";
        
        

    }
}
