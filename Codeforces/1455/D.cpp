#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 505;
int dp[N][N], ndp[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        memset(dp, 0x3F, sizeof(dp));
        dp[0][x] = 0;
        for(int i=1;i<=n;i++){
            memset(ndp, 0x3F, sizeof(ndp));
            for(int j = 0; j <= 500; j++){
                for(int k = 0; k <= 500; k++){
                    if(dp[j][k] == INF_INT) continue;
                    //swap k with v[i];
                    if(v[i] > k && k >= j){
                        ndp[k][v[i]] = min(ndp[k][v[i]], dp[j][k] + 1);
                    }
                    //just keep going
                    if(v[i] >= j){
                        ndp[v[i]][k] = min(ndp[v[i]][k], dp[j][k]);
                    }
                }
            }
            memcpy(dp, ndp, sizeof(dp));
        }
        int ans = INF_INT;
        for(int j=0;j<=500;j++){
            for(int k=0;k<=500;k++){
                ans = min(ans, dp[j][k]);
            }
        }
        if(ans == INF_INT) cout << "-1\n";
        else cout << ans << "\n";
    }
}
