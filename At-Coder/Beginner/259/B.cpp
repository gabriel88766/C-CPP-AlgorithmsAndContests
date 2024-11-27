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
    double a, b, d;
    cin >> a >> b >> d;
    d *= 2*PI;
    d /= 360;
    double x = a  * cos(d) - b * sin(d);
    double y = b * cos(d) + a * sin(d);
    cout << fixed << setprecision(15) << x << " " << y << "\n";
}
