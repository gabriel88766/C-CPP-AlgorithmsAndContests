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
    ll n, x;
    cin >> n >> x;
    ll ans = n;
    ll y = n - x;
    if(x < y) swap(x, y);
    //x >= y;
    while(true){
        if(x % y){
            ans += (2*(x/y)) * y;
            x -= (x/y) * y;
            swap(x, y);
        }else{
            ans += (2*(x/y) - 1) * y;
            break;
        }
    }
    cout << ans << "\n";
}
