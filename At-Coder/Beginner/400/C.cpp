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
    ll cp = 2;
    while(cp <= n){
        ll msq = n / cp;
        ll mx = sqrt(msq);
        while((mx+1)*(mx+1) <= msq) mx++;
        while(mx*mx > msq) mx--;
        ans += mx - mx/2;
        cp *= 2;
    }
    cout << ans << "\n";
}
