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

//THIS CAN GENERATE ALL PARTITIONS (stirling) and return the count
vector<int> part;
ll query(int n, int k, int m = 0){
    int mss = ((1 << n) - 1) ^ m;
    if(__builtin_popcount(mss) < k) return 0;
    if(k == 1) {
        //TODO something with part
        //example:
        part.push_back(mss);
        cout << "{";
        for(int i=0;i<part.size();i++){
            cout << "{";
            for(int j=0;j<n;j++){
                if(part[i] & (1 << j)){
                    cout << j << ",}"[j == 31 - __builtin_clz(part[i])];//part[i] != 0
                }
            }
            cout << ",}"[i + 1 == part.size()];
        }
        part.pop_back();
        cout << "\n";
        return 1;
    }

    ll ans = 0;
    int fb = 1 << __builtin_ctz(~m);
    mss ^= fb;
    for (int s=mss; ; s=(s-1)&mss){ 
        part.push_back(s | fb);
        ans += query(n, k-1, s | fb | m);
        part.pop_back();
        if(s == 0) break;
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cout << query(5, 2);
}
