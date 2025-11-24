#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll binpow(ll a, ll b, ll m){
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
    ll q2 = 0, q5 = 0;
    const ll X = 1'000'000'000'000LL;
    ll v2 = 1, v5 = 1;
    for(int i=1;;i++){
        v2 *= 2;
        if(v2 > X) break;
        q2 += X / v2;
    }
    for(int i=1;;i++){
        v5 *= 5;
        if(v5 > X) break;
        q5 += X / v5;
    }
    ll ans = binpow(2, q2 - q5, 100000);
    for(ll i=1;i<=X;i++){
        ll u = i;
        while(u % 2 == 0) u /= 2;
        while(u % 5 == 0) u /= 5;
        ans = (ans * u) % 100000;
        if(i % 10'000'000 == 0) cout << i << endl;
    }
    cout << ans << "\n";
}
