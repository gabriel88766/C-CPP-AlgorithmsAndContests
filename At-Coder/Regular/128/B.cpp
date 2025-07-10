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
        int r, g, b;
        cin >> r >> g >> b;
        int ans = INF_INT;
        if(r % 3 == g % 3) ans = min(ans, max(r, g));
        if(r % 3 == b % 3) ans = min(ans, max(r, b));
        if(b % 3 == g % 3) ans = min(ans, max(b, g));
        if(ans == INF_INT) ans = -1;
        cout << ans << "\n";
    }
}
