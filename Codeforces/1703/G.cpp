#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll pot[33];

void init(){
    pot[0]= 1;
    for(int i=1;i<33;i++) pot[i] = pot[i-1]*2;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    init();
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<vector<ll>> dp(n+1, vector<ll>(32, -INF_LL));
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
        }
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(31, i); j++){
                if(j == 0) dp[i][j] = dp[i-1][j] + v[i] - k;
                else dp[i][j] = max(dp[i-1][j-1] + v[i]/pot[j], dp[i-1][j] + v[i]/pot[j] - k);
                if(j == 31) dp[i][j] = max(dp[i][j], dp[i-1][j] + 0);
            }
        }
        ll ans = 0;
        for(int i=0;i<=31;i++) ans = max(ans, dp[n][i]);
        cout << ans << "\n";
    }
}
