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
    Mint operator/= (Mint u){ //division untested, MOD not prime, u.v must be coprime with MOD.
        ll x, y;
        ll g = gcd_euclid(u.v, MOD, x, y);
        assert(g == 1);
        (*this) *= x; 
        return *this;
    }
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

//if 0 -> k+1;
//if 1 -> k, k-1, k-2, ..., 0
//if 2 -> k-1, k-2, ..., 0

ll C[62][62];
void init(){
    C[0][0] = 1;
    for(int i=1;i<=61;i++){
        C[i][0] = C[i][i] = 1;
        for(int j=1;j<i;j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}

//numbers less or equal to n with b bits
ll func(ll n, ll cb, ll b){
    if(n < 0 || b < 0) return 0;
    if(cb == 0){
        if(b == 0) return 1;
        else return 0;
    }
    if(n & (1LL << cb)){
        return func(n, cb-1, b-1) + C[cb][b];
    }else return func(n, cb-1, b);
}
Mint calc_arr(ll n){
    ll f1 = n % 2 ? n : n/2;
    ll f2 = n % 2 ? (n+1)/2 : n+1;
    return Mint(f1) * Mint(f2);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        n--;
        /*ll y = n >> (k+1);
        y--;*/
        Mint ans = 0;
        ll cnt = 0;
        ll aux = 1LL << (k+1);
        aux--;
        ans += calc_arr(min(n+1, aux));
        if(n > aux){
            for(int b=1;b<=62;b++){
                if(n & (1LL << b)){
                    if(__builtin_popcountll(n >> b) + b > k){
                        ll aux = (n >> b) << b;
                        ans += calc_arr(min(n-aux+1, (1LL << (k+1 - __builtin_popcountll(n >> b))) -1 ));
                    }
                }
            }
        }
        //cout << ans << " ";
        for(ll lb=1;lb<60;lb++){ //1010111001000 (lb == 3)
            ll y = n >> (lb+1);
            ll x = __builtin_popcountll(y);
            for(ll ki=max(k-lb, 1LL);ki<=k-1;ki++){
                ans += func(y-1, 62, ki) * calc_arr((1LL << (k-ki)) - 1);
            }
        }
        /*for(int i=0;i<=k;i++){
            Mint f1 = func(y, 62, i);
            if(i == 0){
                ans += f1 * calc_arr((1 << (k+1)) - 1);
            }else{
                for(int j=0;i+j <= k;j++){
                    ans += f1 * calc_arr((1 << (k+1-i-j)) - 1) * Mint(C[i+j-1][i-1]);
                    cout << C[i+j-1][i-1] << " ";
                }
            }
            cout << f1 << " " << ans << "\n";
        }
        
        y++;
        ll qt = __builtin_popcountll(y);
        if(qt <= k){
            ll dif = k - qt;
            Mint f1 = 1;
            ll ini = y << (k+1);
            while(ini <= n && dif >= 0){
                ll p = 1LL << (dif+1);
                if(ini + p - 1 <= n){
                    ans += calc_arr(p-1);
                }else{
                    ans += calc_arr(n-ini+1);
                }
                ini += p;
                dif--;
            }
        }*/
        cout << ans << "\n";
    }
}
