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
        ll n;
        cin >> n;
        ll lo = 1, hi = 1414213565, mid;
        while(lo != hi){
            mid = lo + (hi - lo + 1)/2;
            ll res = (mid*(mid-1))/2;
            if(res <= n) lo = mid;
            else hi = mid - 1;
        }
        ll ans = lo;
        ans += (n - ((lo)*(lo-1))/2);
        cout << ans << "\n";
    }
}
