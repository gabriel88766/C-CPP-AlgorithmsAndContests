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
    //freopen("in", "r",    stdin); //test input
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll a1 = b/c + b/d - b/lcm(c,d);
    a--;
    ll a2 = a/c + a/d - a/lcm(c,d);
    ll ans = b - a;
    ans -= a1 - a2;
    cout << ans << "\n";
}
