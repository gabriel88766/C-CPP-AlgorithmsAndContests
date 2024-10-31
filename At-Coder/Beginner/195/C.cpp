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
    ll n;
    cin >> n;
    ll ans = 0;
    ll aux = 1;
    for(int i=1;i<=5;i++){
        aux *= 1000;
        ll aux2 = (n / aux) - 1;
        ll r = (n % aux) + 1;
        if(aux2 >= 0) ans += (aux2 * aux + r);
    }
    cout << ans << "\n";
}
