#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[1 << 19][19];
bool adj[19][19];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a-1][b-1] = adj[b-1][a-1] = true;
    }
    ll ans = 0;
    for(int i=n-1;i>=2;i--){
        memset(dp, 0, sizeof(dp));
        for(int j=0;j<i;j++) if(adj[i][j]) dp[1 << j][j] = 1;
        for(int j=1;j<(1 << i); j++){
            int popcnt = __builtin_popcount(j);
            if(popcnt == 1) continue;
            for(int k=0;k<i;k++){
                if(j & (1 << k)){
                    int last = j ^ (1 << k);
                    for(int u=0;u<i;u++){
                        if(u == k) continue;
                        if((last & (1 << u)) && adj[u][k]) dp[j][k] += dp[last][u];
                    }            
                }
            }
            for(int k=0;k<i;k++){
                if((j & (1 << k)) && adj[k][i]) ans += dp[j][k];
            }
        }
    }
    cout << ans/2;

}
