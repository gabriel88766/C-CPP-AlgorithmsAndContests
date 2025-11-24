#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+4;
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
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    ll ans = 0;
    cout << primes[2] << "\n"; //must be 5
    cout << primes.back() << "\n"; //must be first prime greater than 1000000
    for(int i=2;i+1<primes.size();i++){ //78495 numbers
        string r = to_string(primes[i]);
        ll cg1 = primes[i] % primes[i+1];
        ll cg2 = 1;
        for(int j=0;j<r.size();j++) cg2 *= 10;
        cg2 %= primes[i+1];
        //find first j such that (cg1 + cg2 * j) == 0 mod primes[i+1]
        ll wnt1 = binpow(cg2, primes[i+1] - 2, primes[i+1]);
        assert((wnt1 * cg2) % primes[i+1] == 1);
        ll wnt0 = ((primes[i+1] - cg1) * wnt1) % primes[i+1];
        assert((cg1 + cg2 * wnt0) % primes[i+1] == 0);
        string l = to_string(wnt0);
        ll val = stoll(l + r);
        assert(val % primes[i+1] == 0);
        ans += val;
    }
    cout << ans << "\n";
}
