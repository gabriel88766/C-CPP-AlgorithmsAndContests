#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[3005][3005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    dp[0][1] = 1;
    for(int i=0;i<=3000;i++){
        for(int j=2;j<=3000;j++) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        for(int j=1;j<=3000;j++){
            if(i+j > 3000) continue;
            if(!(j % 2)){
                int ni = j/2 + i, nj = j/2;
                dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % MOD;
            }
        }
    }
    cout << dp[n-k][k];
}   
