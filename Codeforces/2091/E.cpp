#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e7+1000;
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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll mp = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
        ll ans = 0;
        for(ll g = 1; g <= n; g++){
            while(mp >= 0 && primes[mp] * g > n) mp--;
            ans += mp+1;
        }
        cout << ans << "\n";
    }
}
