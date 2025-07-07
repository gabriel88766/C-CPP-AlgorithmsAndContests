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
Mint tr[N][N];
bool ds[N][N];
bool can1[N][N];
Mint dp[N], dpaux[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    dp[0] = 1;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> dsl;
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            dsl.push_back({a, b});
            ds[a][b] = true;
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int cn = j - i + 1;
                for(int x=1;x<=cn;x++){
                    bool ok = true;
                    int cnn = x;
                    for(int k=i;k<=j;k++){
                        if(ds[k][cnn]) ok = false;
                        cnn++;
                        if(cnn > cn) cnn = 1;
                    }
                    if(ok){
                        tr[i][j] += 1;
                        if(x == 1) can1[i][j] = true;
                    }
                }
            }
        }
        
        for(int i=1;i<=n;i++){

            for(int j=0;j<i;j++){
                int len = i - j;
                dp[i] += dp[j] * tr[j+1][i];
                if(can1[j+1][i]){
                    dpaux[i][len] += dp[j];
                    for(int k=len+1;k<=n;k++) dp[i] -= dpaux[j][k];
                }
                // 1 2 3 1 2 and 1 2 3 2 1. Need to be counted only once.
                //as well as 1 2 3 4 5 1 2 3 4
                // subtract one
                // 1 2 3 4 5 6 7 1 2 3 4 is 7-4 or 4-7?? subtract as well
                //damn this is forver
                // 1 2 3 4 5 6 7 1 2 3 4 5 1 2 3(if 7 - 5 - 3 is norm why not 7 - 3 - 5)  

                
                // dp[i] -= dpaux[j][len + 1] * tr[j+1][i];
                
            }
        }
        Mint ans = 0;
        cout << dp[n] << "\n";
        for(auto [a, b] : dsl) ds[a][b] = false;
        for(int i=1;i<=n;i++){
            dp[i] = 0;
            for(int j=1;j<=n;j++){
                tr[i][j] = 0;
                can1[i][j] = false;
                dpaux[i][j] = 0;
            }
        }
    }
}
