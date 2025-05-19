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
    ll dp[4];
    for(int i=0;i<4;i++) dp[i] = -INF_LL;
    int n;
    cin >> n;
    vector<vector<int>> p(n+1, vector<int>(2));
    for(int i=1;i<=n;i++){
        cin >> p[i][0] >> p[i][1];
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int k=0;k<4;k++){
            ll cur = 0;
            for(int j=0;j<2;j++){
                if(k & (1 << j)) cur += p[i][j];
                else cur -= p[i][j];
            }
            dp[k] = max(dp[k], cur);
            cur += dp[3^k];
            ans = max(ans, cur);
            
        }
        cout << ans << "\n";
    }
}
