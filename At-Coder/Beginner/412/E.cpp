#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e7+3;
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
int isnp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    ll l, r;
    cin >> l >> r;
    ll ans = 1;
    for(int i=0;i<primes.size(); i++){
        ll num = 1;
        while(r / num >= primes[i]){
            num *= primes[i];
        }
        while(num >= l + 1 && num != primes[i] && num != 1){
            ans++;
            num /= primes[i];
        }
    }
    for(int i=0;i<primes.size();i++){
        ll fp = (l/primes[i] + 1) * primes[i];
        if(fp == primes[i]) fp += primes[i];
        for(ll j=fp;j<=r;j += primes[i]) isnp[j - l] = 1;
    }
    for(ll j=l+1;j<=r;j++){
        if(!isnp[j-l]) ans++;
    }
    cout << ans << "\n";

}
