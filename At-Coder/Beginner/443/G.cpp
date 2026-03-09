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
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        ll ans = n;
        cout << a*n+b << " " << (a-1)*n + b << " " << (a*n+b)/m << " " << ((a-1)*n+b)/m << "\n";
        ans -= (a*n+b)/m - ((a-1)*n+b)/m;
        cout << ans << "\n";
        ll ans2 = 0;
        for(ll i=1;i<=n;i++){
            if((a*i+b)/m == ((a-1)*i + b)/m) ans2++;
        }
        cout << ans2 << "\n";
    }
}
