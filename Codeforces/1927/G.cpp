#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[2][105];
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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        memset(dp, 63, sizeof(dp));
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            int b = i % 2;
            for(int j=0;j<=n;j++) dp[b][j] = dp[b^1][j];
            int mx = min(i + v[i] - 1, n);
            int mn = i - v[i] + 1;
            for(int j=i-1;j<mx;j++){
                dp[b][mx] = min(dp[b][mx], dp[b^1][j] + 1);
            }
            for(int j=max(mn-1, 0);j<=i;j++){
                dp[b][i] = min(dp[b][i], dp[b^1][j] + 1);
            }
        }
        int b = n%2;
        cout << dp[b][n] << "\n";

    }   
}
