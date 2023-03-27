#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[201][202];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[0][0] = 1;
    for(int i=1;i<=200;i++){
        for(int j=0;j<200;j++){
            if(!j) dp[i][j] = dp[i-1][j+1];
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
        }
    }
    for(int i=1;i<=99;i++) cout << dp[i*2][0] << " ";
}
