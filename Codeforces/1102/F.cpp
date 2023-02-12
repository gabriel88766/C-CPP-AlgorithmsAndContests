#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int adj[17][17];
int badj[17][17];
int dp[17][1 << 16];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    memset(adj, 63, sizeof(adj));
    memset(badj, 63, sizeof(badj));
    cin >> n >> m;
    vector<vector<int>> v(n+1, vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> v[i][j];
        }
    }
    if(n == 1){
        int ans = INF_INT;
        for(int i=1;i<m;i++) ans = min(ans, abs(v[1][i+1] - v[1][i]));
        cout << ans;
    }else{
        //calc adj, badj (if m > 1)
        for(int i=1;i<=n;i++){
            for(int j=(i+1);j<=n;j++){
                if(i == j) continue;
                for(int k=1;k<=m;k++){
                    adj[j][i] = adj[i][j] = min(adj[i][j], abs(v[i][k] - v[j][k]));
                    if(k < m){
                        badj[i][j] = min(abs(v[j][k+1] - v[i][k]), badj[i][j]);
                        badj[j][i] = min(abs(v[i][k+1] - v[j][k]), badj[j][i]);
                    }
                }
            }
        }
        int ans = 0;

        for(int i=1;i<=n;i++){//first.
            memset(dp, 0, sizeof(dp));
            dp[i][1 << (i-1)] = INF_INT;
            for(int j=1;j< (1 << n); j++){
                if(j <= (1 << (i-1))) continue;
                for(int k=0;k<n;k++){
                    if(j & 1 << k){
                        int best = 0;
                        int prev = j & ~(1 << k);
                        for(int w=1;w<=n;w++){
                            best = max(best, min(dp[w][prev], adj[w][k+1]));
                        }
                        dp[k+1][j] = max(dp[k+1][j], best);
                    }
                }
            }
            int last = ((1 << n) - 1);
            for(int j=1;j<=n;j++){
                if(j == i) continue;
                ans = max(ans, min(dp[j][last], badj[j][i]));
            }
        }
        cout << ans;
    }
}
