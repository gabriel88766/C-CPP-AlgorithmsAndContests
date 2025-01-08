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

const int N = 1e7+5;
vector<int> lp(N+1);
vector<int> cf(N+1);
vector<Mint> auxm(N+1), fat(N+1);
vector<int> pr;

void sieve(){
    fat[0] = 1;
    for(int i=1;i<=N;i++) fat[i] = fat[i-1] * i;
    Mint ifat = Mint(1)/fat[N];
    for(int i=N;i>=1;i--){
        Mint i2 = ifat * fat[i-1];
        auxm[i] = (i+1) * i2;
        //i2 = 1/(n+1)! 
        ifat *= i;
    }
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int n, m;
    cin >> n >> m;
    Mint ans = 1;
    for(auto &x: pr){
        if(x <= m){
            ll tt = 0;
            ll cp = 1;
            while(cp * x <= m){
                cp *= x;
                tt += m/cp;
            }
            cf[x] = tt;
            ans *= (tt+1);
        }else break;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        int aux = x;
        Mint cans = ans;
        while(aux != 1){
            cf[lp[aux]]++;
            cans *= auxm[cf[lp[aux]]];
            aux /= lp[aux];
        }
        cout << cans << " ";
        aux = x;
        while(aux != 1){
            cf[lp[aux]]--;
            aux /= lp[aux];
        }
    }
    cout << "\n";
}
