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
        ll a, b;
        cin >> a >> b;
        ll ans = b % a ? a - b%a : 0;
        ll cur = 0;
        while(cur < ans && b/a){
            ll d = ((b-1)%a)/(b/a) + 1;
            a += d;
            cur += d;
            if(!(b % a)){
                ans = min(ans, cur);
                break;
            }
            ans = min(ans, cur + a - b%a);
        }
        if(b < a) ans = min(ans, cur + a - b);
        cout << ans << "\n";
        
    }
}
