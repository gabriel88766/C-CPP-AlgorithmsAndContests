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

Mint dp[101][65000];
Mint aux[65000];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, k;
    cin >> n >> k;
    vector<tuple<int, int, int>> vx; //meaning, from get<0> to get<1>, we can numbers up to get<2>
    int l = 1;
    while(l <= n){
        int r = n/(n/l);
        int val = n/l;
        assert(n / r == val);
        assert((n / (r+1)) != val);
        vx.push_back({l, r, val});
        l = r+1;
    }
    // cout << vx.size() << "\n"; //at most 63244
    dp[0][0] = 1;
    for(int i=0;i<k;i++){
        int p = vx.size() - 1;
        for(int j=0;j<vx.size();j++) aux[j] = 0;
        for(int j=0;j<vx.size();j++){
            auto [l, r, val] = vx[j];
            // if(j == 1) cout << p << " " << get<0>(vx[p]) << " " << val << "\n";
            while(get<0>(vx[p]) > val) p--;
            // if(j == 1) cout << p << " " << get<0>(vx[p]) << " " << val << "\n";
            //now get<0>(vx[p]) <= val <= get<1>(vx[p]);
            //from dp[i][j], I can upd all lower than p multiplied by quantity of numbers in each interval
            //except for p, which can only (val - get<0>(vx[p]) + 1);
            dp[i+1][p] += (val - get<0>(vx[p]) + 1) * dp[i][j]; 
            if(p > 0) aux[p-1] += dp[i][j];
        }
        for(int j=vx.size()-1;j>=0;j--){
            aux[j] += aux[j+1];
            dp[i+1][j] += (get<1>(vx[j]) - get<0>(vx[j]) + 1) * aux[j];
        }
        // for(int j=0;j<vx.size();j++) cout << dp[i+1][j] << " ";
        // cout << "\n";
        
    }
    Mint ans = 0;
    for(int j=0;j<vx.size();j++){
        ans += dp[k][j];
    }
    cout << ans << "\n";
}
