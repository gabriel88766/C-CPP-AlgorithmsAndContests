#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

ll MOD = 1e9+7;
ll fact[2000005];

ll binpow(ll a, ll b, ll m){
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
    ll n, ans = 0, parity = -1, cursum, dividend;
    cin >> n;
    fact[0] = 1;
    for(int i=1;i<=1000000;i++){
        fact[i] = (i * fact[i-1]) % MOD;
    }
    ans = fact[n];
    
    for(int i=1;i<=n;i++){
        ans += MOD;
        dividend = (fact[i] * fact[n-i]) % MOD;
        ans =  (ans + parity * fact[n-i] * divmod(fact[n], dividend, MOD)) % MOD;
        parity *= -1;
    }
    cout << ans;
}


