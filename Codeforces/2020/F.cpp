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


const int N = 3e6+2; //O(N) preprocessing, O(1) query

//Using Mint
Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
Mint nCr(ll a, ll b){
    return fat[a]*invfat[a-b]*invfat[b];
}

int n, k, d, x;

int pr[N]; // 0 if prime, 1 if not prime
Mint val[N], sum[N], sump[N];

void sieve(int n){
    x = n;
    for(ll i=1;i<=n;i++) sum[i] = val[i] = 1, sump[i] = 0;
    sump[1] = 1;
    for(ll i=2; i<=n; i++){
        if(!pr[i]){
            for(ll j = i*i; j <=n; j += i){
                pr[j] = 1; //marking all multiples of i as not prime
            }
            for(ll j=i;j<=n;j+=i){
                int cnt = 0;
                int aux = j;
                while(!(aux % i)){
                    aux /= i;
                    cnt++;
                }
                val[j] *= nCr(d + k * cnt, d);
            }
            sump[i] = nCr(d + k, d);
        }
        sump[i] += sump[i-1];
        sum[i] = val[i];
        sum[i] += sum[i-1];
    }
}


//S(v, p) is the sum of integers up to v, when sieve until p.
//S(v, p) = S(v, p-1) - p*(S(v, p-1) - S(p-1, p-1));
map<ll, map<ll, Mint>> dp;
map<ll, map<ll, Mint>> dp2;
Mint calc_sump(ll n, ll p = 2e7){ // sum for only all p^1
    if(n == 1) return 1;
    if(p*p > n && n <= x) return sump[n];
    // if(dp.count(n) && dp[n].count(p)) return dp[n][p];
    Mint ans = (n-1) * nCr(d + k, d) + 1;
    ll sqt = sqrt(n);
    while(sqt*sqt>n)sqt--;
    while((sqt+1)*(sqt+1) <= n) sqt++;
    for(ll i=2;i<=min(p, sqt);i++){
        if(!pr[i]){
            ans -=  (calc_sump(n/i, i-1) - sump[i-1]);
        }
    }
    return /*dp[n][p] =*/ ans;
}




Mint calc(ll n, ll p = 2){
    if(n == 1 || n  < p) return 1;
    // if(dp2.count(n) && dp2[n].count(p)) return dp2[n][p];
    
    Mint ans = 1;
    ll sqt = sqrt(n);
    while(sqt*sqt>n)sqt--;
    while((sqt+1)*(sqt+1) <= n) sqt++;
    for(ll i=p;i<=sqt;i++){
        if(!pr[i]){
            ll x = 1;
            int cnt = 0;
            while(x*i <= n){
                x *= i;
                cnt++;
                ans += nCr(d + k * cnt, d) * calc(n/x, i+1);
            }
            // ans += i * calc(n/i, i+1);
        }
    }
    //just one more prime
    ans += calc_sump(n) - calc_sump(max(sqt, p-1));
    return /*dp2[n][p] =*/ ans;
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
        dp.clear();
        dp2.clear();
        cin >> n >> k >> d;
        sieve(max((int)pow(n, 0.66), 100));
        if(n <= 100){
            Mint ans = 0;
            cout << sum[n] << "\n";
            continue;
        }else{
            //Lucy dp ??
            cout << calc(n) << "\n";
        }
        
    }
}
