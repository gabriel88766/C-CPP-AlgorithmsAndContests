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
        ll n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        s = " " + s;
        vector<vector<ll>> dp(n+1, vector<ll>(2, INF_LL));
        dp[1][0] = 2*b + a;
        for(int i=2;i<=n;i++){
            dp[i][1] = min(dp[i-1][1] + 2*b + a, dp[i-1][0] + 3*b + 2*a);
            if(s[i] == '0'){
                dp[i][0] = min(dp[i-1][0] + a + b, dp[i-1][1] + 2*a + b);
            }
        }
        cout << dp[n][0] << "\n";
    }
}
