#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool check(ll r, ll x, ll y){
    // (x + 0.5)^2 + (y + 0.5)^2 <= r^2
    // x^2 + x + y^2 + y + 0.5 <= r^2
    //integers:
    // x^2 + x + y^2 + y + 1 <= r^2
    ll fct = x*x + x + y*y + y + 1;
    return fct <= r*r;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int r;
    cin >> r;
    ll ans = 0;
    ll y = r - 1;
    for(int x=0;x<=r-1;x++){
        ll fm = x == 0 ? 1 : 2;
        while(!check(r, x, y)) y--;
        ans += fm * (2*y + 1);
    }
    cout << ans << "\n";
}
