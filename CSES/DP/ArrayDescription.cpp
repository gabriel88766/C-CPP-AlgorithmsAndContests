#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

ll dp[100005][105];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ll> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];

    for(int i = 0; i < n; i++){
        if(nums[i]){ 
            if(i != 0) dp[i][nums[i]] = (dp[i-1][nums[i]-1] + dp[i-1][nums[i]] + dp[i-1][nums[i]+1]) % MOD;
            else dp[i][nums[i]] = 1;
        }else {
            if(i != 0){
                for(int j=1; j<=m; j++){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
                }
            }else{
                for(int j=1;j<=m;j++) dp[i][j] = 1;
            }
        }
    }

    if(nums[n-1]){
        cout << dp[n-1][nums[n-1]];
    }else{
        ll ans = 0;
        for(int i=1;i<=m;i++) ans = (ans + dp[n-1][i] ) % MOD;
        cout << ans;
    }

}
