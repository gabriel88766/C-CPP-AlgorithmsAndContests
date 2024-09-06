#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll MOD;

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
    Mint operator/= (Mint u){ //division untested, MOD not prime, u.v must be coprime with MOD.
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
        ll n, k;
        cin >> n >> k >> MOD;
        vector<vector<Mint>> dp(n+1, vector<Mint>(k+1));
        vector<Mint> jmp(k+1);

        dp[n][0] = 1;
        for(int i=n-1;i>=0;i--){
            if(i != 0){ //must have at least 1 for desired, and
                int aux = n-i; //1, 2, ..
                Mint tnb = Mint(2).pow(aux) - 1;//(1 << aux) - 1; // 1, 3, 7, ...
                vector<Mint> Cb(k+1);
                Mint auxc = 1;
                Cb[0] = 1;
                for(int b=1;b<=k;b++){
                    // C(tnb + b - 1, b)
                    auxc *= Mint(tnb.v + b - 1);
                    auxc /= b;
                    Cb[b] = auxc;
                }
                for(int b=0;b<=k;b++){ // d
                    if(b) jmp[b] = jmp[b-1];
                    else jmp[b] = 0;
                    jmp[b] += Cb[b];
                }
                for(int s=0;s<=k;s++){
                    for(int d=max(s, 1);d<=k;d++){
                        int mx = min((d-1)/2, d-s); // mx < d/2, mx <= d-s;
                        // if(i == 1 && d == 1 && s == 1) cout << s << " " << mx<< " ";
                        dp[i][d] += dp[i+1][s] * jmp[mx];
                    }
                }
            }else{
                //only one option
                for(int j=0;j<=k;j++) dp[i][k] += dp[i+1][j];
            }
        }
        cout << dp[0][k] * Mint(2).pow(n-1) << "\n";
    }
}
