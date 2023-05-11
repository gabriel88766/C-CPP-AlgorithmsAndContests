#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+5;
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
    ll n;
    cin >> n;
    ll ans = 0;
    for(int i=0;primes[i]*primes[i]*primes[i]*primes[i]*primes[i] <= n;i++){
        for(int j=i+1;primes[i]*primes[i]*primes[j]*primes[j]*primes[j] <= n; j++){
            for(int k=j+1;primes[i]*primes[i]*primes[j]*primes[k]*primes[k] <= n; k++) ans++;
        }
    }
    cout << ans;
}
