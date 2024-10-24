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


ll fibo(__int128 k, ll m){
    ll mat[2][2] = {{1, 1}, {1, 0}};
    ll idt[2][2] = {{1, 0}, {0, 1}};
    ll res[2][2] = {{1, 0}, {0, 1}};
    ll aux[2][2] = {{0, 0}, {0, 0}};
    while(k){
        if(k & 1){
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    aux[i][j] = 0;
                    for(int u=0;u<2;u++){
                        aux[i][j] += res[i][u] * mat[u][j];
                    }
                    aux[i][j] %= m;
                }
            }
            for(int i=0;i<2;i++)for(int j=0;j<2;j++) res[i][j] = aux[i][j];
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                aux[i][j] = 0;
                for(int u=0;u<2;u++){
                    aux[i][j] += mat[i][u] * mat[u][j];
                }
                aux[i][j] %= m;
            }
        }
        for(int i=0;i<2;i++)for(int j=0;j<2;j++) mat[i][j] = aux[i][j];
        k >>= 1;
    }
    return (res[1][0] + res[1][1]) % m;
}

int f[300005];
int fg[300005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        if(k == 1) cout << n % MOD << "\n";
        else{
            f[0] = f[1] = 1;
            for(int i=0;i<=k;i++) fg[i] = INF_INT;
    
            for(int i=2;;i++){
                f[i] = (f[i-1] + f[i-2]) % k;
                int g = gcd(f[i], k);
                if(fg[g] == INF_INT){
                    fg[g] = i+1;
                }
                if(g == k) break;
            }
            for(int i=2;i<=k;i++){
                for(int j=2*i;j<=k;j+=i){
                    fg[i] = min(fg[i], fg[j]);
                }
            }
            int cur = 1;
            vector<int> ss;
            int cf = 0;
            do{
                int nx = fg[k/gcd(k,cur)];
                ss.push_back(nx);
                assert(fibo(cf+nx - 1, k) == 0);
                cf += nx;
                cur = fibo(cf, k);
            }while(cur != 1);
            --n;
            ll fac = n / ss.size();
            __int128 xp = 0;
            for(int i=0;i<ss.size();i++) xp += ss[i];
            xp *= fac;
            fac = n % ss.size();
            for(int i=0;i<=fac;i++) xp += ss[i];
            cout << ((ll)(xp % MOD)) << "\n";
        }
    }
}
