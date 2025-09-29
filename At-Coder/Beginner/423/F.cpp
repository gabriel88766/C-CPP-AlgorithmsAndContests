#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[1 << 20];
ll dps[1 << 20][20];
ll lc[1 << 20];
ll a[20];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m, y;
    cin >> n >> m >> y;
    for(int i=0;i<n;i++) cin >> a[i];
    lc[0] = 1;
    for(int i=1;i<(1 << n);i++){
        int j = __builtin_ctz(i);
        ll lcj = lc[i ^ (1 << j)];
        ll g = gcd(lcj, a[j]);
        ll m1 = lcj / g, m2 = a[j];
        if(INF_LL / m1 > m2) lc[i] = m1 *m2;
        else lc[i] = INF_LL;
        dp[i] = y / lc[i];
    }
    ll ans = 0;
    // int msk = (1 << n) - 1;
    // for(int i = (1 << n) - 1; i>= 0; i--){
    //     int x = msk ^ i;
    //     for(int j=0;j<n;j++){
    //         if(i & (1 << j))){
    //             dp[i] -= dp[i | (1 << j)];
    //         }
    //     }
    //     if(__builtin_popcount(i) == m) ans += dp[i];
    //     cout << i << " " << lc[i] << "  " << dp[i] << "\n";
    // }

    // int msk = (1 << n) - 1;
    // for(int i=1;i<(1 << n);i++){//SOS(msk, x). SOS("1001001", 4) = #("1000000") + #("1000001") + #("1001000") + #("1001001")
    //     dps[i][0] = dp[i^msk];//SOS(msk, 0) = #(msk);
    //     for(int j=1;j<n;j++){
    //         int b = 1 << (j-1);
    //         dps[i][j] += dps[i][j-1];
    //         if(i & b) dps[i][j] = dps[i-b][j-1];
    //     }
    //     if(n - __builtin_popcount(i) == m){
    //         ans += dps[i][n-1];
    //         cout << "here" << i << " " << dp[i^msk] << "\n";
    //     }
    // }
    cout << ans << "\n";

}