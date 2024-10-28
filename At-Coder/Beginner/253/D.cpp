#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll calcsum(ll a1, ll an, ll r){
    ll qt = (an - a1)/r + 1;
    return (qt * (a1 + an))/2;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, a, b;
    cin >> n >> a >> b;
    ll lc = lcm(a, b);
    ll ans = calcsum(1, n, 1);
    if(a <= n) ans -= calcsum(a, (n/a)*a, a);
    if(b <= n) ans -= calcsum(b, (n/b)*b, b);
    if(lc <= n) ans += calcsum(lc, (n/lc)*lc, lc);
    cout << ans << "\n";
}
