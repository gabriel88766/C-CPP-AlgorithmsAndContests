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
        int n;
        cin >> n;
        vector<ll> v(n+1);
        int ans = 0;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(v[i] > 4){
                v[i] = 0;
                ans += 1;
            }
        }
        vector<ll> dp(n+1);
        dp[0] = 0;
        int l2 = 0;
        for(int i=1;i<=n;i++){
            if(v[i] > 0) dp[i] = dp[i-1] + 1;
            else dp[i] = dp[i-1];
            /*if(i >= 2){
                if(max(v[i], v[i-1]) <= 2) dp[i] = min(dp[i], dp[i-2] + 1);
            }*/
            if(l2 != 0 && v[i] <= 2){
                if((i-l2) % 2){
                    int d = (i-l2)/2;
                    //cout << l2 << " " << i << "\n";
                    dp[i] = min(dp[l2-1] + 2*d + 1, dp[i]);
                }
            }
            if(v[i] <= 2) l2 = i;
        }

        cout << ans+dp[n] << "\n";
    }
}
 