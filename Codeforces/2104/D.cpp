#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 7e6+5;
int p[N]; // 0 if prime, 1 if not prime
const int M = 4e5+3;
ll ps[M];
vector<ll> primes;
void sieve(){
    primes.push_back(0);
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
    for(int i=1;i<=400000;i++){
        ps[i] = ps[i-1] + primes[i];
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int mx = -1;
        ll cs = 0;
        sort(v.begin(), v.end(), greater<ll>());
        while(mx < n-1){
            if(v[mx + 1] + cs >= ps[mx + 2]){
                mx++;
                cs += v[mx];
            }else break;
        }
        cout << n-mx-1 << "\n";
    }
}
