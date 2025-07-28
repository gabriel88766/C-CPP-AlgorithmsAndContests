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
        ll p, f, cs, cw, s, w;
        cin >> p  >> f >> cs >> cw >> s >> w;
        ll ans = 0;
        for(int i=0;i<=cs;i++){
            if(s * i > p) break;
            ll curw = min(cw, (p - s*i)/w);
            ll cur = curw + i; //what p is carrying
            ll rs = cs - i;
            ll rw = cw - curw;
            ll opt1, opt2;
            opt1 = min(rs, f / s);
            opt1 += min(rw, (f - opt1 * s) / w);
            opt2 = min(rw, f/w);
            opt2 += min(rs, (f - opt2 * w) / s);
            ans = max(ans, cur + max(opt1, opt2));
        }
        cout << ans << "\n";
    }
}
