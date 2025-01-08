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
    int t;
    cin >> t;
    while(t--){
        ll x, y, b;
        cin >> x >> y >> b;
        ll g = gcd(x, y);
        x /= g, y /= g;
        //for finite, b^n need to be multiple of y for some n
        while(y / gcd(y, b) != y) y /= gcd(y, b);
        if(y == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }
}
