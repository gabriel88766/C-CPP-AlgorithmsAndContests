#include <bits/stdc++.h>

using namespace std;

const int N  = 1e6+5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

int dp[N];

int main() {
   int n;
   cin >> n;
   dp[0]=1;
   dp[1]=1;
   dp[2]=2;
   dp[3]=4;
   dp[4]=8;
   dp[5]=16;
   for(int i=6;i<=n;i++){
       dp[i] = (dp[i-1]+dp[i-2])%MOD;
       dp[i] = (dp[i]+dp[i-3])%MOD;
       dp[i] = (dp[i]+dp[i-4])%MOD;
       dp[i] = (dp[i]+dp[i-5])%MOD;
       dp[i] = (dp[i]+dp[i-6])%MOD;
   }
   cout << dp[n];

