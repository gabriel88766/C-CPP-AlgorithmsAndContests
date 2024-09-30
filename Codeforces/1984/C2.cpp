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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<ll>> dp(2, vector<ll>(n+1));
        vector<vector<Mint>> pos(2, vector<Mint>(n+1));
        for(int i=1;i<=n;i++){
            dp[0][i] = INF_LL;
            dp[1][i] = -INF_LL;
        }
        pos[0][0]  = pos[1][0] = 1;
        for(int i=1;i<=n;i++){
            vector<ll> pv;
            ll x;
            cin >> x;
            pv.push_back(dp[0][i-1] + x);
            pv.push_back(abs(dp[0][i-1] + x));
            if(dp[1][i-1] != dp[0][i-1]){
                pv.push_back(dp[1][i-1] + x);
                pv.push_back(abs(dp[1][i-1] + x));
            }
            for(int j=0;j<pv.size();j++){
                if(dp[0][i] > pv[j]){
                    dp[0][i] = pv[j];
                    pos[0][i] = (j < 2 ? pos[0][i-1] : pos[1][i-1]);
                }else if(dp[0][i] == pv[j]){
                    pos[0][i] += (j < 2 ? pos[0][i-1] : pos[1][i-1]);
                }
                
                if(dp[1][i] < pv[j]){
                    dp[1][i] = pv[j];
                    pos[1][i] = (j < 2 ? pos[0][i-1] : pos[1][i-1]);
                }else if(dp[1][i] == pv[j]){
                    pos[1][i] += (j < 2 ? pos[0][i-1] : pos[1][i-1]);
                }
            }
        }
        cout << pos[1][n] << "\n";
    }
}
