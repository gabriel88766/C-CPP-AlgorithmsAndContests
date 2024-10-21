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
    ll x;
    cin >> x;
    ll ans = INF_LL;
    for(int d=1;d<=9;d++){
        for(int r=-9;r<=9;r++){
            for(int sz=1;sz<=18;sz++){
                int xr = d + (sz-1) * r;
                if(xr < 0 || xr > 9) break;
                ll curn = 0;
                int cd = d;
                for(int j=0;j<sz;j++){
                    curn *= 10;
                    curn += cd;
                    cd += r;
                }
                if(curn >= x) ans = min(ans, curn);
            }
        }
    }
    cout << ans << "\n";
}
