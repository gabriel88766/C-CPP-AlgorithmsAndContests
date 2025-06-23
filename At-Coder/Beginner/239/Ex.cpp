#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
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

const int N = 60001;
Mint dp2[N];
map<int, Mint> dp;
Mint mtp;
int n;
Mint inv;

Mint solve(int m){  
    if(m < N) return dp2[m];
    if(dp.count(m)) return dp[m];
    Mint cur = 1;
    int v1 = 2;
    while(v1 <= min(m, n)){
        int d = (m + v1 - 1)/v1, v2;
        if(d == 1) v2 = min(m, n);
        else{
            v2 = m / (d-1);
            if(m % (d-1) == 0) v2--;
            v2 = min(v2, n);
        }
        cur += (v2 - v1 + 1) * solve((m + v1 - 1) / v1) * inv;
        v1 = v2 + 1;
    }
    return dp[m] = cur * mtp;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m;
    cin >> n >> m;
    mtp = Mint(n) / (n-1);
    inv = Mint(1)/n;
    dp[1] = 0;
    m++;
    for(int i=2;i<N;i++){
        Mint cur = 1;
        int v1 = 2;
        while(v1 <= min(i, n)){
            int d = (i + v1 - 1)/v1, v2;
            if(d == 1) v2 = min(i, n);
            else{
                v2 = i / (d-1);
                if(i % (d-1) == 0) v2--;
                v2 = min(v2, n);
            }
            
            cur += (v2 - v1 + 1) * dp2[(i + v1 - 1) / v1] * inv;
            v1 = v2 + 1;
        }
        dp2[i] = mtp * cur;
    }
    cout << solve(m) << "\n";
}
