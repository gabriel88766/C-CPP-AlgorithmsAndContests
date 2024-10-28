#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> dp(m+1, vector<ll>(n+1, INF_LL));
        vector<vector<pair<int,int>>> par(m+1, vector<pair<int,int>>(n+1));
        vector<ll> a(n+1), b(m+1), ps(n+1);
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
             cin >> a[i];
             ps[i] = ps[i-1] + a[i];
        }
        for(int i=1;i<=m;i++) cin >> b[i];
        for(int i=1;i<=m;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = dp[i-1][j];
                par[i][j] = {i-1, j};
            }
            for(int j=0;j<=n;j++){

                if(dp[i][j] == INF_LL) continue;
                //source is state i, j
                int ind = prev(upper_bound(ps.begin(), ps.end(), ps[j] + b[i])) - ps.begin();
                assert(ind >= j);
                assert(ind <= n);
                if(dp[i][j] + m-i < dp[i][ind]){
                    dp[i][ind] = dp[i][j] + m-i;
                    par[i][ind] = {i, j};
                }
            }
        }
        if(dp[m][n] != INF_LL) cout << dp[m][n] << "\n";
        else cout << "-1\n";
    }
}
