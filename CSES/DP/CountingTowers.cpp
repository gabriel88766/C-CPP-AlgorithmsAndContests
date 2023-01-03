#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

ll dp[1000005][2];

//hint: analyse recursion from 1 to 2
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=2;i<=1000000;i++){
        dp[i][0] = ( 4 * dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = ( dp[i-1][0] + 2 * dp[i-1][1]) % MOD;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
    }
}
