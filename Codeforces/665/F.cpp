#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+2e4;
vector<ll> primes;
ll mi[N], p[N];
void mobius(){ //another sieve.
    for(ll i =1; i<N;i++) mi[i] = 1;
    for(ll i=2; i<N; i++){
        if(!p[i]){
            primes.push_back(i);
            for(ll j = i; j < N; j += i){
                mi[j] *= -1;
                if(j != i) p[j] = 1;
            }
            for(ll j = i*i; j < N; j += i*i){
                mi[j] = 0;
            }
        }
    }
}
ll sz;
ll cntdiv(ll n, ll x, ll lp){
    ll ans = n / x;
    for(int i = lp+1; i< sz;i++){
        if(x*primes[i] > n) continue;
        ans -= cntdiv(n, x*primes[i], i);
    }
    return ans;
}

ll cntp(ll n){
    return cntdiv(n, 1, -1);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    mobius();
    ll n, ans = 0;
    cin >> n;
    //letsgo... 4 divisors. p1*p1*p1 or p1*p2
    for(int i=2;i * i * i <= n; i++){
        if(!p[i]) ans++;
    }
    //count pairs p1 p2 lower than 320000
    for(int i = 0; i< primes.size();i++){ //i have too many seconds... hehe O(7e8)
        for(int j=i+1; j < primes.size();j++){//i could do a binary search... could...
            if(primes[i]*primes[j] <= n){
                ans++;
            }
        }
    }
    //last... p1 < 320000 and p2 > 320000, count prime numbers up to n/p
    sz = primes.size();
    for(int i=0;i<sz;i++){
        ll x = n / primes[i];
        if(x < N) break;
        ll y = cntp(x);
        ans += (y - 1);
    }
    cout << ans << "\n";
}
