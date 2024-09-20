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
    ll n, l, r;
    cin >> n >> l >> r;
    // l <= x <= r and n^x < n
    // then, x has some highest bit that n also has.
    ll ans = 0;
    for(int j=61;j>=0;j--){
        ll cur = 1LL << j;
        if(cur & n){
            ll mv = 2*cur - 1;
            if(mv >= l && cur <= r) ans += min(r, mv) - max(cur, l) + 1;
        }
    }
    cout << ans << "\n";
}
