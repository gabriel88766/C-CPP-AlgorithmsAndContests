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
    // freopen("out", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll l, r, rans;
        cin >> l >> r;
        ll ans = 1;
        for(int i=0;i<60;i++){
            ll xc = 1LL << i;
            if((l & xc) == 0 && (r & xc) == xc) ans *= 2;
            else break;
        }
        ll hf = (l + r + 1) / 2;
        ll xr = l ^ r;
        if((hf ^ xr) == hf - 1 && ans < xr) ans *= 2;
        ans -= 1;
        cout << ans << "\n";
    }
}
