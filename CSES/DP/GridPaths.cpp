#include <bits/stdc++.h>

using namespace std;

const int N  = 1e3+2;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

int dp[N][N];
char allowed[N][N];

int main() {
    int n;
    char k;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cin >> k;
           allowed[i][j] = (k == '*' ? false : true);
        }
    }
    if(allowed[0][0])
        dp[0][0] = 1;

     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(i==0 || j==0){
               if(allowed[i][j]){
                   if(i==0 && j!=0){
                       dp[i][j] = dp[i][j-1];
                   }else if(j==0 && i!=0){
                       dp[i][j] = dp[i-1][j];
                   }
               }
           }else{
               if(allowed[i][j]){
                   dp[i][j] = dp[i-1][j] + dp[i][j-1];
                   if(dp[i][j] >= MOD) dp[i][j] -= MOD;
               }
           }
        }
    }



    cout << dp[n-1][n-1];
}
