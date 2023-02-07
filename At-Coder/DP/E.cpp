//Knapsack I
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
ll dp[105][N]; //min weight to get at least j value;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, W;
    cin >> n >> W;
    vector<ll> vals(n+1), w(n+1);
    for(int i=1;i<=n;i++){
        ll a,b;
        cin >> w[i] >> vals[i];
    }
    memset(dp, 63, sizeof(dp));
    for(int i=0;i<=n;i++) dp[i][0] = 0; //always possible to get value 0
    for(int i=1;i<=n;i++){
        for(int j=100000; j>=1;j--){
            dp[i][j] = dp[i][j+1];
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if(j >= vals[i]) dp[i][j] = min(dp[i][j], dp[i-1][j-vals[i]] + w[i]);

        }
    }
    int ans = 1;
    while(dp[n][ans+1] <= W) ans++;
    cout << ans;

}
