#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int v[4];
int l[8];
int rcst[256][1001];
int dp[4][256];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, a, b, c;
    cin >> n >> v[1] >> v[2] >> v[3];
    for(int i=0;i<n;i++) cin >> l[i];
    memset(dp, 63, sizeof(dp));
    for(int j=0;j<=1000;j++) rcst[0][j] = INF_INT;
    dp[0][0] = 0;
    for(int i=1;i<(1 << n);i++){
        int cst = __builtin_popcount(i) * 10 - 10;
        int sum = 0;
        for(int j=0;j<n;j++){
            if(i & (1 << j)) sum += l[j];
        }
        for(int j=0;j<=1000;j++){
            rcst[i][j] = abs(j - sum) + cst;
        }
    }
    for(int i=1;i<=3;i++){
        int ans = INF_INT;
        for(int j=0;j<(1 << n);j++){
            for(int k=0;k<(1 << n);k++){
                if((j & k) == k){
                    int nmsk = j ^ k;
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + rcst[nmsk][v[i]]);
                }
            }
            // cout << dp[i][j] << " ";
            ans = min(ans, dp[i][j]);
        }
        // cout << "\n";
        if(i == 3) cout << ans << "\n";
    }
}
