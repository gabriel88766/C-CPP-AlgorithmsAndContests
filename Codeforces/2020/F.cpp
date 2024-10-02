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

const int M = 1.2e6;
int pr[M]; // 0 if prime, 1 if not prime
Mint val[M], sum[M]; 
ll cnt[M];// cnt[M];
vector<int> primes;

void sieve2(){
    primes.push_back(0);
    for(ll i=2; i<M; i++){
        if(!pr[i]){
            for(ll j = i*i; j <=M; j += i){
                pr[j] = 1; //marking all multiples of i as not prime
            }
            primes.push_back(i);
            cnt[i] = 1;
        }
        cnt[i] += cnt[i-1];
    }
}


ll y;
vector<tuple<ll, ll, ll>> qrs;

struct Bit{
    vector<int> bit;
    int n;
    Bit(int sz){
        n = sz;
        bit.resize(sz+1);
    }
    int query(int b){ // sum in range [1, b]
        int ans = 0;
        for(int i = b; i > 0; i -= i & -i){
            ans += bit[i];
        }
        return ans;
    }
    void add(int b){ //add value to position b
        for(int i = b; i <= n; i += i & -i){
            bit[i]++;
        }
    } 
};


ll fphi2(ll n, ll a, int s){
    if(a == 0) return n; //sum 1, n if sum
    else{
        if(n < primes[a]) return 0;
        if((a-1) && n/primes[a] <= y){
            qrs.push_back({n/primes[a], a-1, -s});
            return fphi2(n, a-1, s);
        }else
        return fphi2(n, a-1, s) - fphi2(n/primes[a], a-1, -s); //multiply here if sum
    }
}

ll cntp(ll n){
    if(n < M) return cnt[n];
    ll cy = pow(n, 0.385);
    ll a = upper_bound(primes.begin(), primes.end(), cy) - primes.begin();
    y = n/primes[a]+1;
    qrs.resize(0);
    ll ans = fphi2(n, a, 1);
    sort(qrs.begin(), qrs.end(), [&](tuple<ll, ll, ll> &a, tuple<ll, ll, ll> &b){
        auto [n1, a1, s1] = a;
        auto [n2, a2, s2] = b;
        return a1 < a2;
    });
    Bit b(y);
    int p = 1;
    vector<char> vis(y+1, false);
    for(auto [n, a, s] : qrs){
        while(p <= a){
            for(int i=primes[p];i<=y;i+=primes[p]){
                if(!vis[i]){
                    b.add(i);
                    vis[i] = true;
                }
            }
            p++;
        }
        if(s == 1) ans += n - b.query(n);
        else ans -= n - b.query(n);
    }
    ans += a - 1;
    p = lower_bound(primes.begin(), primes.end(), n/primes[a+1]) - primes.begin();
    for(int i=a+1;i<primes.size();i++){
        while(primes[i] * primes[p] > n) p--;
        if(p < i) break;
        ans -= p-i+1; //prefix sum if sum.
    }
    return ans;
}

//Begin solve. 2020F
int n, k, d, x;
void sieve(int n){
    x = n;
    for(ll i=1;i<=n;i++) sum[i] = val[i] = 1;
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
        }
        sum[i] = val[i];
        sum[i] += sum[i-1];
    }
}


//S(v, p) is the sum of integers up to v, when sieve until p.
//S(v, p) = S(v, p-1) - p*(S(v, p-1) - S(p-1, p-1));
Mint calc(ll n, ll p = 2){
    if(n == 1 || n  < p) return 1;
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
        }
    }
    ans += (cntp(n) - cntp(max(sqt, p-1))) * nCr(d + k, d);
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve2();
    init();
    int t;
    cin >> t;
    while(t--){
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
