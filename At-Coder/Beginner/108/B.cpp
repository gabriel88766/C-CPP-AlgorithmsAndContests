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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx = x2 - x1;
    int dy = y2 - y1;
    dy = - dy;
    swap(dx, dy);
    int x3 = x2 + dx, y3 = y2 + dy;
    cout << x3 << " " << y3 << " ";
    dy = - dy;
    swap(dx, dy);
    int x4 = x3 + dx, y4 = y3 + dy;
    cout << x4 << " " << y4 << "\n";
}
