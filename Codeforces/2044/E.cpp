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
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        ll pt = 1, ans = 0;
        while(pt <= 1'000'000'000){
            ll lm = ((l2 + pt - 1)/pt);
            ll gm = r2/pt;
            if(min(gm, r1) >= max(lm, l1)) ans += min(gm, r1) - max(lm, l1) + 1;
            pt *= k;
        }
        cout << ans << "\n";
    }
}   
