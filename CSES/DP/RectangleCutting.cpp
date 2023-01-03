#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

vector<vector<int>> dp(505, vector<int> (505, INF_INT));
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    for(int i=1;i<=500;i++){
        dp[i][i] = 0;
        dp[i][1] = i-1;
        dp[1][i] = i-1;
    }
    int cnt = 0;
    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            for(int k=1;k<=(j-1);k++){
                dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
            }
            for(int k=1;k<=(i-1);k++){
                dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
            }
            
        }
    }
    int a, b;
    cin >> a >> b;
    cout << dp[a][b];
    
}
