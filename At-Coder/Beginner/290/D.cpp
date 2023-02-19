#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        ll n, d, k;
        cin >> n >> d >> k;
        if(d > n) d = d % n;
        ll g = __gcd(n, d);
        ll x = n/g;    
        ll q = (k-1) / x;
        ll r = (k-1) % x;
        cout << (r * d + q) % n << "\n"; 
    }
}
