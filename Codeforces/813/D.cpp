#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
int dp[N][N];
int nxtInc[N];
int nxtDec[N];
int nxtMod[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    for(int i=1;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        //from dp[i][0]
        for(int j=i+1;j<=n;j++){
            dp[j][i] = max(dp[j][i], dp[i][0] + 1);
        }
        for(int j=1;j<=i;j++){
            nxtDec[j] = max(nxtDec[j], i+1);
            nxtInc[j] = max(nxtInc[j], i+1);
            nxtMod[j] = max(nxtMod[j], i+1);
            while(nxtDec[j] <= n && v[nxtDec[j]] != v[j] - 1) nxtDec[j]++;
            while(nxtInc[j] <= n && v[nxtInc[j]] != v[j] + 1) nxtInc[j]++;
            while(nxtMod[j] <= n && v[nxtMod[j]] % 7 != v[j] % 7) nxtMod[j]++;
            if(j == i) break;
            if(nxtDec[j] <= n) dp[nxtDec[j]][i] = max(dp[nxtDec[j]][i], dp[i][j] + 1);
            if(nxtInc[j] <= n) dp[nxtInc[j]][i] = max(dp[nxtInc[j]][i], dp[i][j] + 1);
            if(nxtMod[j] <= n) dp[nxtMod[j]][i] = max(dp[nxtMod[j]][i], dp[i][j] + 1);
        }
        for(int j=0;j<i;j++){
            if(nxtDec[i] <= n) dp[nxtDec[i]][j] = max(dp[nxtDec[i]][j], dp[i][j] + 1);
            if(nxtInc[i] <= n) dp[nxtInc[i]][j] = max(dp[nxtInc[i]][j], dp[i][j] + 1);
            if(nxtMod[i] <= n) dp[nxtMod[i]][j] = max(dp[nxtMod[i]][j], dp[i][j] + 1);
        }
    }
    int mx = 0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx << "\n";
}
