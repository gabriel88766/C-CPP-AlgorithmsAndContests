#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int mid = 250001;
ll dp[500005], ndp[500005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int j=0;j<500005;j++) dp[j] = -INF_LL;
    dp[mid] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<500005;j++) ndp[j] = -INF_LL;
        int w, h, b;
        cin >> w >> h >> b;
        for(int j=0;j<500005;j++){
            if(j >= w && dp[j-w] != -INF_LL){
                ndp[j] = max(ndp[j], dp[j-w] + b);
            }
            if(j < 500005-w && dp[j+w] != -INF_LL){
                ndp[j] = max(ndp[j], dp[j+w] + h);
            }
        }
        memcpy(dp, ndp, sizeof(ndp));
    }
    ll ans = 0;
    for(int j=mid;j<500005;j++){
        ans = max(ans, dp[j]);
    }
    cout << ans << "\n";
}
