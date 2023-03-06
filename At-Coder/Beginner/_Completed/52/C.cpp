#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1001;
int p[N]; // 0 if prime, 1 if not prime
int f[N];
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
    //freopen("in", "r", stdin); test input
    sieve();
    int n;
    cin >> n;
    for(int i=2;i<=1000;i++){
        if(p[i]) continue;
        for(int j=2;j<=n;j++){
            if(j < i) continue;
            int cnt = 0, aux = j;
            while(!(aux % i)){
                aux /= i;
                f[i]++;
            }
        }
    }
    ll ans = 1;
    for(int i=2;i<=1000;i++){
        if(f[i]) ans = (ans * (f[i]+1)) % MOD;
    }
    cout << ans;
}
