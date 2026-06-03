#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e7+1;
int p[N]; // 0 if prime, 1 if not prime
vector<ll> primes;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            primes.push_back(i);
        }
    }
}

ll binpow(ll a, ll b, ll m){
    a %= m;
    ll ans = 1;
    while(b){
        if(b & 1) ans = (a * ans) % m;
        a = (a*a) % m;
        b >>= 1;
    }
    return ans;
}

// a^((p-1)/2) mod p;
int legendrex(ll a, ll p){
    if(a < 0) a = (a % p) + p;
    ll val = binpow(a, (p-1)/2, p);
    return val > 1 ? -1 : val;
}

//finds n, n^2 == x mod p
ll cipolla(ll x, ll p){
    if(legendrex(x, p) == -1) return -1; //not a quadratic residue
    ll fn = -1;
    for(ll i=1; i < p;i++){ //this is fast
        if(legendrex(i*i - x, p) == -1){
            fn = i;
            break;
        }
    }
    if(fn == -1) assert(false);
    ll w = fn * fn - x;
    ll b = (p+1)/2;
    pair<ll, ll> ans = {1, 0};
    pair<ll, ll> mx = {fn, 1LL};
    auto multiply = [&](pair<ll, ll> a, pair<ll, ll> b){
        ll in = a.first * b.first + ((a.second * b.second) % p) * w;
        in %= p;
        ll re = (a.first * b.second + a.second * b.first) % p;
        return make_pair(in, re);
    };
    while(b){
        if(b & 1){
            ans = multiply(ans, mx);
        }
        mx = multiply(mx, mx);
        b >>= 1;
    }
    assert(ans.second == 0);
    ll fx = ans.first;
    if(fx < 0) fx += p;
    return fx;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("out", "w", stdout); //test input
    sieve();
    ll ans = 0;
    //n² - 3n - 1 = 0 => 4n² - 12n - 4 = 0 => (2n - 3)² - 13 = 0 => (2n - 3)² == 13 (mod p²)
    //solve first (2n - 3)² == 13 (mod p) then expand
    for(auto pr : primes){
        if(pr <= 13){
            //bruteforce
            for(int i=1;i<pr*pr;i++){
                if((i*i - 3*i - 1) % (pr * pr) == 0){
                    ans += i;
                    break;
                }
            }
            continue;
        }
        ll x = cipolla(13, pr);
        if(x == -1) continue;
        //2n-3 == x and p-x;
        ll v1 = (x + 3) % pr;
        ll v2 = (pr - x + 3) % pr;
        v1 = (v1 * binpow(2, pr-2, pr)) % pr;
        v2 = (v2 * binpow(2, pr-2, pr)) % pr;
        ll mn = INF_LL;
        for(auto x : {v1, v2}){
            ll vt = x * x - 3 * x - 1;
            ll m1 = vt % (pr * pr);
            if(m1 == 0){
                //it's ok;
                mn = min(mn, x);
                continue;
            }
            m1 /= pr;
            m1 = (pr - m1);
            //2*n*u - 3 * u == -m1/p (mod p);
            // u = m1 / (2*n - 3); here n = x
            if((2*x - 3) % pr == 0){
                //impossible
                continue;
            }
            ll u = (m1 * binpow(2 * x - 3, pr - 2, pr)) % pr;
            mn = min(mn, u * pr + x);
        }
        if(mn != INF_LL) ans += mn;

        
    }
    cout << ans << "\n";
}
 