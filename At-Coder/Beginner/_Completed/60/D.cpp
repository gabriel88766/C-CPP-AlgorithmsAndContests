#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[101][301];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, W;
    cin >> n >> W;
    vector<int> w(n+1), v(n+1);
    memset(dp, 192, sizeof(dp));
    for(int i=1;i<=n;i++) cin >> w[i] >> v[i];
    int ref = w[1];
    dp[0][0] = 0;
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            for(int k=(w[i]-ref);k<=300;k++){
                if(dp[j-1][k-w[i]+ref] < 0) continue;
                dp[j][k] = max(dp[j][k], dp[j-1][k-w[i]+ref] + v[i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=300;j++){
            ll res = ref;
            res *= i;
            res += j;
            if(res <= W) ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}
