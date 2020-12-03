#include <bits/stdc++.h>

using namespace std;

long long int dp[5005][5005][2], v[5005], ps[5005];


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int n;
    cin >> n;
    ps[0] = 0;
    for(int i=1;i<=n;i++) {cin >> v[i]; ps[i] = ps[i-1] + v[i];}

    for(int i=1;i<=n;i++){
        dp[1][i][1] = 0;
        dp[1][i][0] = v[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=(n-i+1);j++){
            dp[i][j][0] = max(ps[j+i-1] - ps[j-1] - dp[i-1][j][1], ps[j+i-1] - ps[j-1] - dp[i-1][j+1][1] );
            dp[i][j][1] = max(ps[j+i-1] - ps[j-1] - dp[i-1][j][0], ps[j+i-1] - ps[j-1] - dp[i-1][j+1][0] );
        }
    }
    if(!(n % 2)) cout << dp[n][1][1]; else cout << dp[n][1][0];

}
