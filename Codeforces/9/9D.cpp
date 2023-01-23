#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[36][36];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    dp[0][0] = 1;
    dp[1][1] = 1;
    ll ans = 0;
    for(int i=2;i<=35;i++){
        for(int j=2;j<=i;j++){
            for(int k=0;k<=(i-1);k++){
                ll total = 0;
                for(int w=0;w<=(j-1);w++){
                    total += dp[k][w];
                    if((j-1) != w) total += dp[k][w];
                }
                dp[i][j] +=  total * dp[i-k-1][j-1]; 
            }
        }
    }
    int n,h;
    cin >> n >> h;
    for(int i=h;i<=n;i++) ans += dp[n][i];
    cout << ans;
}
