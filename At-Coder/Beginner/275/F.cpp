#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[3005][2], ndp[3005][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    memset(dp, 63, sizeof(dp));
    dp[0][1] = 0; //1 means last was chosen
    for(int i=1;i<=n;i++){
        memset(ndp, 63, sizeof(ndp));
        int x;
        cin >> x;
        for(int j=0;j<=m;j++){
            ndp[j][0] = min(dp[j][1] + 1, dp[j][0]);
        }
        for(int j=x;j<=m;j++){
            ndp[j][1] = min(dp[j-x][1], dp[j-x][0]);
        }
        for(int j=0;j<=m;j++){
            
            dp[j][0] = ndp[j][0];
            dp[j][1] = ndp[j][1];
        }
    }
    for(int i=1;i<=m;i++){
        if(min(dp[i][0], dp[i][1]) != INF_INT) cout << min(dp[i][0], dp[i][1]) << "\n";
        else cout << "-1\n";
    }
}
