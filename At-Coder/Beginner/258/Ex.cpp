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

void mult(vector<vector<Mint>> &a, vector<vector<Mint>> &b){
    vector<vector<Mint>> ans(2, vector<Mint>(2));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ans[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        }
    }
    a = ans;
}

vector<vector<Mint>> fmat(ll n){// Fn Fn-1 // Fn-1 Fn-2
    vector<vector<Mint>> ans = {{1, 0}, {0, 1}}, aux = {{1, 1}, {1, 0}};
    while(n){
        if(n & 1) mult(ans, aux);
        mult(aux, aux);
        n >>= 1;
    }
    return ans;
}

Mint dp[100005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, S;
    cin >> n >> S;
    vector<ll> v(n+2);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    v[n+1] = S;
    Mint ans = 0;
    pair<Mint,Mint> aux, aux2 = {1, 0};
    for(int i=1;i<=n+1;i++){
        vector<vector<Mint>> mat = fmat(v[i]-v[i-1]);
        aux = {mat[0][0] * aux.first + mat[0][1] * aux.second, mat[1][0] * aux.first + mat[1][1] * aux.second};
        aux2 = {mat[0][0] * aux2.first + mat[0][1] * aux2.second, mat[1][0] * aux2.first + mat[1][1] * aux2.second};
        dp[i] = aux2.second - aux.second;
        aux.first += dp[i];
    }

    cout << dp[n+1] << "\n";
}
