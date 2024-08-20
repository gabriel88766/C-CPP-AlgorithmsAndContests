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
        vector<vector<int>> dp(2, vector<int>(2002));
        for(int i=0;i<=2001;i++) dp[0][i] = i;
        for(int i=1;i<=n;i++){
            int b = i%2;
            for(int j=0;j<=2001;j++) dp[b][j] = INF_INT;
            int x;
            cin >> x;
            for(int k=0;k<=2001;k++){
                if(k >= x) dp[b][k-x] = min(dp[b][k-x], dp[b^1][k]);
                if(k + x <= 2001) dp[b][k+x] = min(dp[b][k+x], max(dp[b^1][k], k+x)); 
            }
        }
        int b = n % 2;
        int ans = INF_INT;
        for(int i=0;i<=2001;i++) ans = min(ans, dp[b][i]);
        cout << ans << "\n";
        
    }
}
