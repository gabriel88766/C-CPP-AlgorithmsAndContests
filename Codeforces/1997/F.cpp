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

void ntt(vector<Mint> &a, int n, int s) { //31^(2^23) == 1 (mod 998244353), so, for example, if n = 2^16, w1 = 31^(2^7)
    Mint w1 = 31;
    for(int i = n; i < (1 << 23); i <<= 1) w1 *= w1;
    for (int i=0, j=0; i<n; i++) {
        if (i>j) swap(a[i], a[j]);
        for (int l=n/2; (j^=l) < l; l>>=1);
    }
    //w1^n = 1
    for(int i = 1; (1<<i) <= n; i++){
        int M = 1 << i;
        int K = M >> 1;
        Mint wn = w1.pow( n + s*(n/M)); 
        for(int j = 0; j < n; j += M) {
            Mint w = 1;
            for(int l = j; l < K + j; ++l){
                Mint t = w*a[l + K];
                a[l + K] = a[l] - t;
                a[l] = a[l] + t;
                w *= wn;
            }
        }
    }
}

ll dp1[55005];
Mint dp2[55005][11], aux[55005][11], ps[55005][11]; 
// ll ps[55005][11];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, x;
    cin >> n >> x >> m;
    vector<ll> fib = {0, 1, 1};
    do{
        int sz = fib.size();
        fib.push_back(fib[sz-1] + fib[sz-2]);
    }while(fib.back() <= 55000);
    //sum max = 55 * 1000 = 55000
    memset(dp1, 63, sizeof(dp1));
    dp1[0] = 0;
    for(int i=1;i<=55000;i++){
        for(auto x : fib){
            if(i >= x) dp1[i] = min(dp1[i], dp1[i-x] + 1);
        }
    }
    //optimize here.
    dp2[0][1] = 1;
    for(int i=1;i<=n;i++){ //1000*55000*10= 
        int curm = i*55;
        for(int d=0;d<=curm;d++){
            for(int nj=1;nj<=x;nj++){
                ps[d][nj] = ps[d][nj-1] + dp2[d][nj];
            }
        }
        dp2[0][1] = 0;
        for(int d=curm;d>=0;d--){
            for(int nj=1;nj<=x;nj++){
                if(fib[nj] <= d){
                    dp2[d][nj] = ps[d - fib[nj]][nj];
                }
            }
        }
    }

    Mint ans = 0;
    for(int i=1;i<=55000;i++){
        if(dp1[i] == m){
            for(int j=1;j<=x;j++) ans += dp2[i][j];
        }
    }
    cout << ans << "\n";
}