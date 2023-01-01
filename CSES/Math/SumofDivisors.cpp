#include <bits/stdc++.h>
typedef long long int ll;
const int N = 1e6;
const ll MOD = 1e9+7;
using namespace std;
vector<ll> divisors;
vector<vector<int>> factors;

int p[N+5];

ll binpow(ll a, ll  b, ll  m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) 
            ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

ll divmod(ll a, ll b, ll m){
    return (a * binpow(b, m-2, m)) % m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, top, ans=0, mod=1e9+7, million = 1e6, bp, ep;
    cin >> n;
    top = min(n, million);
    for(int i=1;i<=top;i++){
        ans += (n/i)*i;
        ans %= mod;
    }
    bp = million + 1;
    for(int i = n/(million+1); i >= 1; i--){
        ep = n/i;
        ll factor1 = (ep - bp + 1) % mod;
        factor1 *= (ep+bp) % mod;
        factor1 %= mod;
        ll sum = (divmod(factor1, 2, mod) * i) % mod;
        ans = (ans + sum) % mod;
        bp = ep+1;
    }
    cout << ans;
}
