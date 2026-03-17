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
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    ll ans = 0;
    for(int i=l;i<=r;i++){
        int abi = abs(i);
        if(i % 2 == 0){
            int cl = max(-abi, d);
            int cr = min(abi, u);
            if(cr >= cl) ans += cr - cl + 1;
        }
        if(u > abi){
            int cl = max(abi, d-1);
            int cr = u;
            ans += cr/2 - cl/2;
        }
        if(d < -abi){
            int cl = abs(min(-abi, u+1));
            int cr = abs(d);
            ans += cr/2 - cl/2;
        }
    }
    cout << ans << "\n";
}
