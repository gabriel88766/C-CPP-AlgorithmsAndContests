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
    int n;
    cin >> n;
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double mx = x1 + x2;
    double my = y1 + y2;
    mx /= 2;
    my /= 2;
    double a = 2*PI/n;
    double vx = x1 - mx;
    double vy = y1 - my;
    //multiply by cos
    double rx = cos(a) * vx - sin(a) * vy;
    double ry = sin(a) * vx + cos(a) * vy;
    mx += rx;
    my += ry;
    cout << setprecision(15) << fixed << mx << " " << my << "\n";
}
