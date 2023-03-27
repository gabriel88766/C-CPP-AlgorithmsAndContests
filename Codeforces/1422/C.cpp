#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
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
    string n;
    cin >> n;
    int k = n.size();
    ll ans = 0, aux = 0;
    reverse(n.begin(), n.end());
    for(int i=0;i<k;i++){
        ans = (ans + (n[i]-'0')* aux) % MOD;
        ll aux2 = k-i-1;
        aux2 = (aux2 * (aux2+1)) % MOD;
        aux2 = (aux2 * binpow(2, MOD-2)) % MOD;
        ans = (ans + aux2*(n[i]-'0')*binpow(10,i)) % MOD;
        aux = (aux + binpow(10,i)*(i+1)) % MOD;
    }
    cout << ans;
}
