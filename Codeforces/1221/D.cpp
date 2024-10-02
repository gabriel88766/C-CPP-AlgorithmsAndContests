#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll, ll>> vp(n+1);
        for(int i=1;i<=n;i++){
            cin >> vp[i].first >> vp[i].second;
        }
        vector<vector<ll>> dp(n+1, vector<ll>(3, INF_LL));//minimum cost to satisfy and vp[i].first be equals to vp[i].first + j
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            auto va = vp[i-1].first;
            auto vc = vp[i].first;
            auto cc = vp[i].second;
            for(int j=0;j<=2;j++){
                for(int k=0;k<=2;k++){
                    if(va + j == vc + k) continue;
                    dp[i][k] = min(dp[i][k], dp[i-1][j] + k * cc);
                }
            }
        }
        ll ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
        cout << ans << "\n";

    }
}
