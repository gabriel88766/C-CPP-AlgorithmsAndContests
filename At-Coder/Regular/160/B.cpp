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
        int n;
        cin >> n;
        ll ans = 0;
        for(int y=1;y*y<=n;y++){
            int mz = n / y;
            ll qz = mz - y;
            ll qx = y - 1;
            ans = (ans + 6*qz*qx + 3*qz + 3*qx + 1) % MOD; 
        }
        cout << ans << "\n";
    }
}
