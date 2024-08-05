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
    ll n;
    ll a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    vector<ll> b(n+1);
    for(int i=1;i<=n;i++) cin >> b[i];
    ll ans = -INF_LL, bsum = -INF_LL, minv = INF_LL, maxv = -INF_LL;
    for(int i=n;i>=1;i--){
        minv = min(minv, b[i]);
        maxv = max(maxv, b[i]);
        ll bv = (a[2] > 0 ? a[2] * maxv : a[2] * minv);
        ll cans = a[0] * b[i];
        bsum = max(bsum, (a[1] + a[2]) * b[i]);
        bsum = max(bsum, a[1]*b[i] + bv);
        cans += bsum;
        ans = max(ans, cans);
    }




    cout << ans << "\n";
    
}
