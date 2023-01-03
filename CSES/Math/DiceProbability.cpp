#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

double dp[105][605];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    dp[0][0] = 1;
    double ans = 0;
    int n, a, b;
    cin >> n >> a >> b;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=600;j++){
            if(j >= 6) dp[i][j] += dp[i-1][j-6]/6;
            if(j >= 5) dp[i][j] += dp[i-1][j-5]/6;
            if(j >= 4) dp[i][j] += dp[i-1][j-4]/6;
            if(j >= 3) dp[i][j] += dp[i-1][j-3]/6;
            if(j >= 2) dp[i][j] += dp[i-1][j-2]/6;
            dp[i][j] += dp[i-1][j-1]/6;
        }
    }
    for(int i=a; i<=b ;i++){
        ans += dp[n][i];
    }
    cout << fixed << setprecision(6) <<  ans ;

}
