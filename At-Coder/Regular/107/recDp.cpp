#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[3005][3005];
bool vis[3005][3005];

ll calc(int i, int j){
    if(j > 3000) return 0;
    if(i <= 0 || j <= 0) return 0;
    if(2*j <= 3000 && !vis[i][2*j]) dp[i][2*j] = calc(i, 2*j), vis[i][2*j] = true;
    if(!vis[i-1][j-1]) dp[i-1][j-1] = calc(i-1, j-1), vis[i-1][j-1] = true;
    if(2*j <= 3000 ) return (dp[i][2*j] + dp[i-1][j-1])%MOD;
    else return dp[i-1][j-1];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    for(int i=0;i<=3000;i++) dp[i][i] = 1, vis[i][i] = true;
    for(int i=1;i<=3000;i++){
        for(int j=1;j<=3000;j++){
            if(!vis[i][j]) dp[i][j] = calc(i, j);
        }
    }
    cout << dp[n][k];
}   
