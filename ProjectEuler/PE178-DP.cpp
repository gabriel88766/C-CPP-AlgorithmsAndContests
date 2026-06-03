#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[1 << 10][10], ndp[1 << 10][10];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<=9;i++) dp[1 << i][i] = 1;
    ll ans = 0;
    for(int i=2;i<=40;i++){
        memset(ndp, 0, sizeof(ndp));
        for(int j=0;j<(1 << 10);j++){
            for(int k=0;k<=9;k++){
                if(k != 0) ndp[j | (1 << (k-1))][k-1] += dp[j][k];
                if(k != 9) ndp[j | (1 << (k+1))][k+1] += dp[j][k];
            }
        }
        memcpy(dp, ndp, sizeof(ndp));
        for(int j=0;j<=9;j++) ans += dp[(1 << 10) - 1][j];
    }
    cout << ans << "\n";
}
