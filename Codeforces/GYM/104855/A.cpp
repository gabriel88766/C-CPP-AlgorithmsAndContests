#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6+1;
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
    vector<int> v;
    for(int i=100;i<=78400;i++) v.push_back(i);
    shuffle(v.begin(), v.end(), rng);
    int t;
    cin >> t;
    cout << primes[99] << "\n";
    while(t--){
        ll num = 0;
        for(int i=0;i<3;i++){
            cout << "? " << primes[v[i]] << "\n";
            cout.flush();
            ll ans;
            cin >> ans;
            ans *= 2;
            ans /= primes[v[i]];
            num = max(num, ans);
        }
        cout << "! " << num << "\n";
    }
    
}
 