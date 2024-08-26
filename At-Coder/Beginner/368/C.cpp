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
    int n;
    cin >> n;
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll h;
        cin >> h;
        ll lo = ans + 1, hi = ans + h;
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            ll ttk = (mid/3 - ans/3);
            ttk = (mid - ans - ttk) + ttk * 3;
            if(ttk >= h) hi = mid;
            else lo = mid + 1;
        }
        ans = lo;
    }
    cout << ans << "\n";
}
