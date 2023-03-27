#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[2001][4005];
ll v[2001];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[0][2000] = 1;
    int n;
    ll k;
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> v[i];
    if(k == 1){
        cout << 0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(v[i-1] == v[i%n]){
            for(int j=0;j<=4000;j++) dp[i][j] = (dp[i-1][j]*k) % MOD;
        }else{
            for(int j=0;j<=4000;j++){
                if(j == 0){ //j= -1 is 0
                    dp[i][j] = (dp[i-1][j]*(k-2) + dp[i-1][j+1]) % MOD;
                }else if(j == 4000){ //j=4001 is 0
                    dp[i][j] = (dp[i-1][j]*(k-2) + dp[i-1][j-1]) % MOD;
                }else{
                    dp[i][j] = (dp[i-1][j]*(k-2) + dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
                }
            }
        }
    }

    ll ans = 0;
    for(int i=2001;i<=4000;i++) ans = (ans + dp[n][i]) % MOD;
    cout << ans;
}
