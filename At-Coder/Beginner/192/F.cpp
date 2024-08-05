#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[101][101];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n+1);
    ll ans = INF_LL;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int k=1;k<=n;k++){//quantity of numbers choose
        memset(dp, 192, sizeof(dp));
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){ //v[i]
            for(int j=i-1;j>=0;j--){ //quantity current
                for(int r=0;r<k;r++){
                    if(dp[j][r] < 0) continue;
                    int d = (r + v[i]) % k;
                    dp[j+1][d] = max(dp[j+1][d], dp[j][r] + v[i]);
                }
            }
        }
        if(dp[k][x % k] >= 0){
            ll cur = (x - dp[k][x%k])/k;
            ans = min(ans, cur);
        }
    }
    cout << ans << "\n";
}
