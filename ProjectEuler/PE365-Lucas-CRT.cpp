#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//Lucas, let (n, k) in mod p, 
// if n = ax p^x + ax-1 p^(x-1) + ... + a0 
// and k = bx p^x + bx-1 p^(x-1) + ... + b0
//then (n, k) is prod of (ai, bi) mod p;
ll MOD;
// template <int MOD_val=998244353>
struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
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
    Mint& operator*= (const Mint &u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint& operator+= (const Mint &u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint& operator-= (const Mint &u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint& operator/= (const Mint &u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint &u) const { return v == u.v;}
    bool operator!= (const Mint &u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 1e6+1;
Mint fat[N], invfat[N];
void init_lucas(int p){
    MOD = p;
    fat[0] = 1;
    for(int i=1;i<p;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[p-1] = 1/fat[p-1];
    for(int i=p-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}

Mint nCr_lucas(int a, int b){
    if(a < b) return 0;
    return fat[a] * invfat[b] * invfat[a-b];
}

Mint lucas(ll n, ll m){
    Mint ans = 1;
    while(n || m){
        ans *= nCr_lucas(n % MOD, m % MOD);
        n /= MOD;
        m /= MOD;
    }
    return ans;
}


//problem AX + BY = C, find X and Y => AX == C mod(B) => X == C/A mod(B)
ll gcd_euclid(ll a, ll b, ll &x, ll &y){ //solves ax+by = g where g = gcd(a,b)
    if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd_euclid(b, a % b, x1, y1); //if b > a then this step reverses it
    x = y1;
    y = x1 - y1 * (a/b); 
    return d;
}

bool find_xy(ll a, ll b, ll c, ll &x, ll &y){ //first solution for x >= 0, if x > 0, make '<=' in the if.
    ll g = gcd_euclid(abs(a), abs(b), x, y);
    if(c % g) return false;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    x = (x * c/g)  % (abs(b)/g); //if risk of overflow, make x positive (if(x < 0) x %= m, x += m;) and apply mulmod
    if(x < 0) x += abs(b)/g;
    y = (c - a*x) / b;
    return true;
}

//This code below come from 
//https://github.com/imeplusplus/icpc-notebook/blob/master/math/extended_euclid.cpp
bool crt_auxiliar(ll a, ll b, ll m1, ll m2, ll &ans){
    ll x, y;
    if(!find_xy(m1, m2, b - a, x, y)) return false;
    ll lcm = m1 / __gcd(m1, m2) * m2;
    ans = ((a + x % (lcm / m1) * m1) % lcm + lcm) % lcm;
    return true;
}

// find ans such that ans = a[i] mod b[i] for all 0 <= i < n or return false if not possible
// ans + k * lcm(b[i]) are also solutions
bool crt(vector<ll> a, vector<ll> b, ll &ans){
    int n = a.size();
    assert(a.size() == b.size() && "size of a isn't equal size of b in CRT"); 
    if(!b[0]) return false;
    ans = a[0] % b[0];
    ll l = b[0];
    for(int i = 1; i < n; i++){
    if(!b[i]) return false;
        if(!crt_auxiliar(ans, a[i] % b[i], l, b[i], ans)) return false;
        l *= (b[i] / __gcd(b[i], l));
    }
    return true;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<pair<ll, ll>> vcong;
    for(int p = 1000; p <= 5000; p++){
        bool isp = true;
        for(int j=2;j<p;j++){
            if(p % j == 0) isp = false;
        }
        if(isp){
            init_lucas(p);
            vcong.push_back({p, lucas(1'000'000'000'000'000'000LL, 1'000'000'000LL).v});
        }
    }
    ll ans = 0;
    for(int i=0;i<vcong.size();i++){
        for(int j=i+1;j<vcong.size();j++){
            for(int k=j+1;k<vcong.size();k++){
                vector<ll> a = {vcong[i].second, vcong[j].second, vcong[k].second};
                vector<ll> b = {vcong[i].first, vcong[j].first, vcong[k].first};
                ll cans;
                crt(a, b, cans);
                ans += cans;
            }
        }
    }
    cout << ans << "\n";
}
