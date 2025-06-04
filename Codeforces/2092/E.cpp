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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        map<pair<int, int>, int> mp;
        ll n, m, k;
        cin >> n >> m >> k;
        for(int i=0;i<k;i++){
            int a, b, x;
            cin >> a >> b >> x;
            mp[{a, b}] = x;
        }
        int ctt = 0, c1 = 0, tt = 2*(n-2) + 2*(m-2);
        for(int i=2;i<m;i++){
            if(mp.count({1, i})){
                ctt++;
                if(mp[{1, i}] == 1) c1++;
            }else break;
            if(mp.count({n, i})){
                ctt++;
                if(mp[{n, i}] == 1) c1++;
            }else break;
        }
        for(int i=2;i<n;i++){
            if(mp.count({i, 1})){
                ctt++;
                if(mp[{i, 1}] == 1) c1++;
            }else break;
            if(mp.count({i, m})){
                ctt++;
                if(mp[{i, m}] == 1) c1++;
            }else break;
        }  
        if(ctt == tt){
            if(c1 % 2) cout << 0 << "\n";
            else cout << Mint(2).pow(n*m-k) << "\n";
        }else{
            Mint ans = Mint(2).pow(n*m - k - 1);
            cout << ans << "\n";
        }

    }
}
