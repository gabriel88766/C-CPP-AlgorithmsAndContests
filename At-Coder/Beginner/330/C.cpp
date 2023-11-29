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
    ll high=0;
    for(;high*high <= n;high++);
    ll ans = INF_LL;
    for(ll i=0;i*i<=n;i++){
        ll aux = n - i*i;
        ll lo = 0, hi = high;
        while(lo != hi){
            ll mid = lo + (hi - lo + 1) / 2;
            if(mid*mid <= aux) lo = mid;
            else hi = mid - 1; 
        }
        ans = min(ans, abs(aux - lo*lo));
        ans = min(ans, abs(aux - (lo+1)*(lo+1)));
    }
    cout << ans << "\n";
}
