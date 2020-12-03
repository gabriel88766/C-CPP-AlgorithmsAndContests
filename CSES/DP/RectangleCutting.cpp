#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
int dp[505][505];

void solve(){
    for(int i=1;i<=500;i++){
        dp[1][i] = i-1;
        dp[i][1] = i-1;
    }
    for(int i=2;i<=500;i++){
        for(int j=2;j<=500;j++){
            int mincur = INF;
            if(i!=j){
                for(int k=1;k<i;k++){
                    mincur = min(mincur,dp[i-k][j]+dp[k][j]);
                }
                for(int k=1;k<j;k++){
                    mincur = min(mincur,dp[i][j-k]+dp[i][k]);
                }
                dp[i][j] = mincur+1;
            }else dp[i][j] = 0;
        }
    }

}

int main(){
solve();
int a,b;
cin >> a >> b;
cout << dp[a][b];
}
