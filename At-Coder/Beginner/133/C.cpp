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
    int l, r;
    cin >> l >> r;
    int ans = INF_INT;
    int ln = (r / 2019) * 2019;
    // assert(ln <= r);
    if(ln >= l && ln <= r) cout << "0\n";
    else{
        assert(r - l <= 2020);
        for(ll i=l;i<=r;i++){
            for(ll j=i+1;j<=r;j++){
                ll rem = (i * j) % 2019;
                ans = min(ans, (int)rem);
            }
        }
        cout << ans << "\n";
    }
}
