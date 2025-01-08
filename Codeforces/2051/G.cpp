#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 20;
int te[M];
int adj[M][M], cur[M][M];
int dp[1 << M][M];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=q;i++){
        int x;
        char c;
        cin >> x >> c;
        x--;
        if(c == '+'){
            te[x]++;
            //all cur[x][j]++
            for(int j=0;j<n;j++){
                if(j == x) continue;
                cur[x][j]++;
                adj[x][j] = max(adj[x][j], cur[x][j]);
            }
        }else{
            //all cur[j][x]++
            for(int j=0;j<n;j++){
                if(j == x) continue;
                cur[j][x]--;
                adj[j][x] = max(adj[j][x], cur[j][x]);
            }
        }   
    }
    memset(dp, 63, sizeof(dp));
    for(int i=0;i<n;i++) dp[1 << i][i] = 0;
    for(int i=1;i<(1 << n);i++){
        for(int j=0;j<n;j++){
            if(i & (1 << j)){
                for(int k=0;k<n;k++){
                    if(i & (1 << k)) continue;
                    dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + adj[j][k]);
                }
            }
        }
    }
    int ans = INF_INT;
    for(int i=0;i<n;i++) ans = min(ans, dp[(1 << n) - 1][i] + te[i]);
    ans += n;
    cout << ans << "\n";
}
