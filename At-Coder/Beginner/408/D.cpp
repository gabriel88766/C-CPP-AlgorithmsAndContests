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
        string s;
        cin >> n >> s;
        vector<vector<int>> dp(n+1, vector<int>(3, INF_INT));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        s = " " + s;
        for(int i=1;i<=n;i++){
            dp[i][0] = dp[i-1][0], dp[i][1] = dp[i-1][1], dp[i][2] = dp[i-1][2];
            if(s[i] == '1') dp[i][0]++, dp[i][2]++;
            else dp[i][1]++;
            dp[i][1] = min(dp[i][1], dp[i][0]); //transition
            dp[i][2] = min(dp[i][2], dp[i][1]); //transition
        }
        cout << min({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
    }
}
