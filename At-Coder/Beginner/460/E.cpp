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
        ull n, m;
        cin >> n >> m;
        ull ans = 0;
        ull cur = 1;
        for(int i=1;i<=19;i++){
            cur *= 10;
            ull fn = cur / 10;
            ull ln = min(n, cur - 1);
            if(ln >= fn){
                ull cc = cur - 1;
                ull g = gcd(cc, m);
                ull cm = m / g;
                ll cs = (n / cm) % MOD;
                cs *= (ln - fn + 1) % MOD;
                cs %= MOD;
                ans += cs;
                ans %= MOD;
            }else break;
        }
        cout << ans << "\n";
    }
}
