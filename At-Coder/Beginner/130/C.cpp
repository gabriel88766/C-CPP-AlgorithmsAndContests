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
    int W, H, x, y;
    cin >> W >> H >> x >> y;
    double S = W;
    S *= H;
    S /= 2;
    cout << fixed << setprecision(6);
    if(x == (W-x) && y == (H-y)) cout << S << " " << 1;
    else cout << S << " " << 0;
   
}
