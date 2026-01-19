#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    a %= MOD, b %= MOD, c %= MOD;
    d %= MOD, e %= MOD, f %= MOD;
    ll r1 = (a * b) % MOD;
    r1 = (r1 * c) % MOD;
    ll r2 = (d * e) % MOD;
    r2 = (r2 * f) % MOD;
    ll res = (r1 - r2) % MOD;
    if(res < 0) res += MOD;
    cout << res << "\n";
}
