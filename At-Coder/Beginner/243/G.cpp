#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[1000005], ps[1000005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[1] = 1;
    ps[1] = 3;
    for(int i=2;i<=1'000'000;i++){
        dp[i] = dp[i-1] + dp[(int)(sqrt(i))];
        ps[i] = ps[i-1] + (2*i+1) * dp[i];
    }
    int t;
    cin >> t;
    while(t--){
        ll x;
        cin >> x;
        ll sqt = sqrt(x);
        while(sqt*sqt > x) sqt--;
        while((sqt+1)*(sqt+1) <= x) sqt++;
        if(sqt <= 1000) cout << dp[sqt] << "\n";
        else{
            //well, dp1[i] = dp1[i-1] + dp1[(int)(sqrt(i))]; forever
            //need dp1[sqt]
            //another recurrence.. dp[x] = dp[sqrt(1)] + dp[sqrt(2)] + ... + dp[sqrt(sqt)]
            // 3 * dp[1] + 5 * dp[2] + 7 * dp[3] + ...
            ll sq2 = sqrt(sqt);
            while(sq2*sq2 > sqt) sq2--;
            while((sq2+1)*(sq2+1) <= sqt) sq2++;
            ll ans = (sqt - sq2*sq2 + 1) * dp[sq2];
            sq2--;
            ans += ps[sq2];
            cout << ans << "\n";
        }
    }
}
