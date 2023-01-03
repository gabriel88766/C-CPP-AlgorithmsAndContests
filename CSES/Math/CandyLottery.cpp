#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

double dp[105][105];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=k;i++){ //init
        dp[1][i] = (1/(double)k);
    }
    for(int i=2;i<=n;i++){
        double ps = 0;
        for(int j=1;j<=k;j++){
            dp[i][j] = ps/(double)k + (double)j/k * dp[i-1][j];
            ps += dp[i-1][j];
        }
    }
    double ans = 0;
    for(int i=1;i<=k;i++){
        ans += i*dp[n][i];
    }
    cout << fixed << setprecision(6) << ans;
}
