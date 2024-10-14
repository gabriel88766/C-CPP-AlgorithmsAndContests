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


const int M = 1e5+5;
int p[M]; // 0 if prime, 1 if not prime
vector<int> divs[M], fac[M];
int mi[M], av[M];
Mint val[M], aux[M];

void sieve(){
    for(ll i=1;i<M;i++){
        mi[i] = 1;
        for(ll j=i;j<M;j+=i){
            divs[j].push_back(i);
        }
    }
    for(ll i=2;i<M;i++){
        if(!p[i]){
            for(ll j=i*i;j<M;j+=i*i) mi[j] = 0;
            for(ll j=i;j<M;j+=i){
                mi[j] *= -1;
                p[j] = 1;
            }
        }
    }
    ll tst = 0;
    for(int i=1;i<M;i++){
        fac[i].resize(divs[i].size());
        for(int j=0;j<divs[i].size();j++){
            av[divs[i][j]] = j;
        }
        for(int j=0;j<divs[i].size();j++){
            for(auto x : divs[i/divs[i][j]]){
                fac[i][av[x*divs[i][j]]] += mi[x] * divs[i][j]; 
            }
        }
    }
}

const int N = 5e5+3;
Mint p2[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    p2[0] = 1;
    for(int i=1;i<N;i++) p2[i] = p2[i-1] * 2;
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    Mint ans = 0;
    for(int i=1;i<=n;i++){
        ans = 2 * ans;
        for(int j=0;j<divs[v[i]].size();j++){
           ans += val[divs[v[i]][j]] * fac[v[i]][j];
        }

        for(auto x : divs[v[i]]){
            val[x] += p2[i-1];
        }
        cout << ans << "\n";
    }

}
