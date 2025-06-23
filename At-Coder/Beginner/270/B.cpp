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
    int x, y, z;
    cin >> x >> y >> z;
    if(x < 0){
        x = -x;
        y = -y;
        z = -z;
    }
    if(y > x || y < 0) cout << x << "\n";
    else if(z < 0) cout << x + 2*abs(z) << "\n";
    else if(z < y) cout << x << "\n";
    else cout << "-1\n"; 
}
