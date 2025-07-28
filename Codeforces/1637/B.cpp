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
        int n;
        cin >> n;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        ll ans = 0; 
        vector<vector<int>> mex(n+1, vector<int>(n+1));
        for(int i=1;i<=n;i++){
            vector<bool> used(n+2, false);
            int cm = 0;
            for(int j=i;j<=n;j++){
                if(v[j] <= n+1) used[v[j]] = true;
                while(used[cm]) cm++;
                mex[i][j] = cm;
            }
        }
        for(int i=1;i<=n;i++){
            //i is the begin.
            vector<int> dp(n+1, 0);
            dp[i-1] = 0;
            for(int j=i;j<=n;j++){
                for(int l=i;l<=j;l++){
                    dp[j] = max(dp[j], dp[l-1] + mex[l][j] + 1);
                }
                ans += dp[j];
            }
        }

        cout << ans << "\n";
    }
}
