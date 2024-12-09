#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e6+1;
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
    // 9 divisors. p^8 or p^2 q^2
    ll ans = 0;
    for(auto x : primes){
        if(x*x*x*x*x*x*x*x <= n) ans++;
        else break;
    }
    for(int i=0;i<primes.size();i++){
        for(int j=i+1;j<primes.size();j++){
            ll a = primes[i];
            ll b = primes[j];
            if(a*b > n) break;
            if(a*b*b > n) break;
            if(a*a*b*b <= n) ans++;
            else break;
        }
    }
    cout << ans << "\n";
}
