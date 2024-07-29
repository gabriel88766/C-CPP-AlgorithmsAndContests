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
        ll ans = 0;
        ll r;
        cin >> r;
        ll sq1 = r*r;
        ll sq2 = (r+1) * (r+1);
        for(ll x=1;x<=r;x++){
            ll lr = sqrt(r*r - x*x);

            while(lr*lr + x*x < sq1) lr++;
            while(lr*lr + x*x < sq2){
                ans += 4;
                lr++;
            } 
        }
        cout << ans << "\n";
    }
}
