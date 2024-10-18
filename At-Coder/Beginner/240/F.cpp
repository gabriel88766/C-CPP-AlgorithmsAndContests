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
        ll n, m;
        cin >> n >> m;
        ll ans;
        ll cp = 0;
        ll cv = 0;
        for(int i=1;i<=n;i++){
            ll x, y;
            cin >> x >> y;
            if(i == 1) ans = x;
            ll fv = cv + x; 
            ll lv = cv + x*y;
            //find max  cp +  k * cv + ((k)*(k+1))/2 * x
            //find last k : cv + k * x >= 0
            if(x < 0 && cv >= 0){
                ll g = cv / abs(x);
                g = min(g, y);
                if(g > 0){
                    ll clv = cv + g * x;  
                    ll cm = cp + ((fv + clv) * g)/2;
                    ans = max(ans, cm);
                }
            }
            cp += ((fv + lv) * y) / 2;
            ans = max(ans, cp);
            cv = lv;
        }
        cout << ans << "\n";
    }
}   
