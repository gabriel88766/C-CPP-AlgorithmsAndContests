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
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    ll ans = 1;
    for(int j = 2; j <= min(g, 1000001LL); j++){
        if(g % j == 0){
            ans++;
            while(g % j == 0) g /= j;
        }
    }
    if(g != 1) ans++;
    cout << ans << "\n";
}
