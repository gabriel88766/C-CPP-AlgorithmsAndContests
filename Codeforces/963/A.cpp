#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+9; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll binpow(ll a, ll b, ll m = MOD){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    ll ans = 0;
    string s;
    cin >> s;
    ll aux;
    for(int i=0;i<k;i++){
        aux = 1;
        if(s[i] == '-') aux = MOD-1;
        aux  = (aux * binpow(a,n-i)) % MOD;
        aux = (aux * binpow(b, i)) % MOD;
        ans = (ans + aux) % MOD;
    }
    aux = ans;
    ans = 0;
    ll x = (b * binpow(a, MOD-2)) % MOD;
    x = binpow(x, k);
    if(x == 1){
        ans = (aux * (n+1)/k) % MOD;
    }else{
        ans = (aux * (binpow(x, (n+1)/k) - 1 + MOD)) % MOD;
        ans = (ans * binpow(x+MOD-1, MOD-2)) % MOD;
    }
    cout << ans;

}
