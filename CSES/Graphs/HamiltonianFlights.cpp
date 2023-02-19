//DP TSP
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll pos[21][21];
ll dp[1 << 18][20];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        pos[a][b]++;
    }
    dp[0][1] = 1;
    for(int i=1;i<(1 << (n-2)); i++){
        for(int j=2;j<n; j++){
            int msk = 1 << (j-2);
            if(i & msk){
                for(int k=1;k<n;k++){
                    dp[i][j] = (dp[i][j] + pos[k][j]*dp[i ^ msk][k]) % MOD;
                }
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<n;i++){
        ans += pos[i][n] * dp[(1 << (n-2)) - 1][i];
        ans %= MOD;
    }
    cout << ans;
}
