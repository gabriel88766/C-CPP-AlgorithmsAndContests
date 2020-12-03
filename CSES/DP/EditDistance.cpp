#include <bits/stdc++.h>

using namespace std;
/*
TWXFUABGBNLTBFNSUVQW
GPNJILFXJUIZPLTVUIB
*/
int dp[5005][5005];

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
string s,t;
cin >> s >> t;
int n=s.size(),m=t.size();
dp[0][0]=0;
for(int i=1;i<=n;i++){
    dp[i][0]=i;
}
for(int i=1;i<=m;i++){
    dp[0][i]=i;
}
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        int opt1 = dp[i-1][j-1] + ( s[i-1]==t[j-1] ? 0 : 1);
        int opt2 = dp[i-1][j] + 1;
        int opt3 = dp[i][j-1] + 1;
        dp[i][j] = min(opt1,min(opt2,opt3));
    }
}

cout << dp[n][m];

}
