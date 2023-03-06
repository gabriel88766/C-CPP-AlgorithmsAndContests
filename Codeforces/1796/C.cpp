#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
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
        ll l, r;
        cin >> l >> r;
        ll sz = 64-__builtin_clzll(r/l);
        if(sz == 1){
            cout << sz << " ";
            cout << r-l+1 << "\n";
            continue;
        }
        ll pos1 = 1, pos2 = 1;
        for(int i=0;i<(sz-2);i++){
            pos1 *= 2;
            pos2 *= 2;
        }
        pos1 *= 2, pos2 *= 3;
        ll ans = 0;
        ll aux1 = r/pos1;
        ans += (aux1 - l + 1);
        ll aux2 = r/pos2;
        if(aux2 >= l) ans = (ans + (aux2 - l + 1)*(sz-1)) % MOD;
        cout << sz << " " << ans << "\n";
    }
}
