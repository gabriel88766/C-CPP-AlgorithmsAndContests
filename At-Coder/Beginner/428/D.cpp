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
        ll c, d;
        cin >> c >> d;
        //up to 19 digits up to 2 * 10^18
        ll ans = 0;
        for(int s2 = 1; s2 <= 10; s2++){
            ll mn = stol(to_string(c) + "1" + string(s2-1, '0'));
            ll mn2 = stol(to_string(c) + to_string(c+1));
            mn = max(mn, mn2);
            ll mx = stol(to_string(c) + string(s2, '9'));
            ll mx2 = stol(to_string(c) + to_string(c+d));
            mx = min(mx, mx2);
            if(mx < mn) continue;
            ll fs = 2'000'000'000;
            ll ls = 0;
            for(int k=1'000'000'000;k>=1;k>>=1){
                while(fs - k >= 0 && (fs-k)*(fs-k) >= mn) fs -= k;
                while(ls + k <= 3'000'000'000 && (ls + k) * (ls + k) <= mx) ls += k;
            }
            if(ls >= fs) {
                ans += ls - fs + 1;
            }
         }
        cout << ans << "\n";
    }
}
