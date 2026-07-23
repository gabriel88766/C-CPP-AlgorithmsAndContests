#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[21][21];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[0][0] = 1;
    for(int i=0;i<=20;i++){
        for(int j=0;j<=20;j++){
            if(i != 0) dp[i][j] += dp[i-1][j];
            if(j != 0) dp[i][j] += dp[i][j-1];
        }
    }
    cout << dp[20][20] << "\n";
}
