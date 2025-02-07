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
    ll a, b, n;
    cin >> a >> b >> n;
    //find maximum ax / b - a * (x/b) , x <= n
    ll mr;
    if(b - 1 <= n){
        mr = b - 1;
    }else mr = n;
    ll ans = (a*mr)/b - a * (mr/b);
    cout << ans << "\n";
}
