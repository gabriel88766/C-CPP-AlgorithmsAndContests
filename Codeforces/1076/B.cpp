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
    ll n;
    cin >> n;
    ll lf = -1;
    for(ll i=2;i*i<=n;i++){
        if(!(n % i)){
            lf = i;
            break;
        }
    }
    if(lf == -1) lf = n;
    ll ans = 1;
    n -= lf;
    assert(!(n % 2));
    ans += n/2;
    cout << ans << "\n";
}