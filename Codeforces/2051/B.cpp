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
        ll n, a, b, c;
        cin >> n >> a >> b >> c;
        ll ans = 0;
        ans = n/(a+b+c);
        n -= ans * (a+b+c);
        ans *= 3;
        if(n == 0);
        else if(n <= a) ans += 1;
        else if(n <= a + b) ans += 2;
        else ans += 3;
        cout << ans << "\n";
    }
}
