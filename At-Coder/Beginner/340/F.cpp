#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


ll gcd_euclid(ll a, ll b, ll &x, ll &y){ //solves ax+by = g where g = gcd(a,b)
    if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd_euclid(b, a % b, x1, y1); //if b > a then this step reverses it
    x = y1;
    y = x1 - y1 * (a/b); 
    return d;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll x, y;
    cin >> x >> y;
    if(x == 0 || y == 0){
        if(x == 0){
            if(2 % y) cout << "-1\n";
            else cout << 2/y << " " << 0 << "\n";
        }else{
            if(2 % x) cout << "-1\n";
            else cout << 0 << " " << 2/x << "\n";
        }
    }else{
        ll a, b;
        ll g = gcd_euclid(-y, x, a, b);
        if(2 % g) cout << "-1\n";
        else{
            if(abs(g) == 2) cout << a << " " << b << "\n";
            else cout << 2*a << " " << 2*b << "\n";
        }
    }
}
 