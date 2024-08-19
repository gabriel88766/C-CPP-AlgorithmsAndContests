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
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, q;
    cin >> n >> q;
    vector<vector<Mint>> h(4, vector<Mint>(n+1));
    vector<vector<Mint>> ps1(4, vector<Mint>(n+1)), ps2(4, vector<Mint>(n+1));
    for(int i=0;i<4;i++){
        for(int j=1;j<=n;j++){
            h[i][j] = uniform_int_distribution<int>(257, 1000000000)(rng);
        }
    }
    vector<ll> a(n+1), b(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        for(int j=0;j<4;j++){
            ps1[j][i] = ps1[j][i-1] + a[i] * h[j][a[i]];
        }
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
        for(int j=0;j<4;j++){
            ps2[j][i] = ps2[j][i-1] + b[i] * h[j][b[i]];
        }
    }
    for(int i=0;i<q;i++){
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        bool ok = true;
        for(int j=0;j<4;j++){
            if(ps1[j][r] - ps1[j][l-1] != ps2[j][R] - ps2[j][L-1]) ok = false;
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
