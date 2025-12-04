#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[6005][6005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("streetlamp_safety_input.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout); //test input

    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n;
        cin >> n;
        vector<int> a(n+1), b(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = INF_LL;
            }
        }
        vector<int> mn(n+1);
        dp[0][0] = 0;
        mn[0] = 0;
        for(int i=1;i<=n;i++){
            mn[i] = max(mn[i-1], b[i]);
            for(int j=b[i]; j<=n;j++) dp[i][j] = dp[i-1][j];
            ll s = 0;
            set<pair<int, int>> sx;
            multiset<int> mxx;
            for(int j=i;j>=1;j--){
                if(b[j]){ 
                    sx.insert({j-b[j] + 1, b[j]});
                    mxx.insert(b[j]);
                }
                while(sx.size() && prev(sx.end())->first == j){
                    mxx.erase(mxx.find(prev(sx.end())->second));
                    sx.erase(prev(sx.end()));
                }
                s += a[j];
                int nd = mxx.size() ? *prev(mxx.end()) : 0;
                nd = max(nd, mn[j-1]);
                // cout << nd << " ";
                dp[i][i - j + 1] = min(dp[i][i - j + 1], s + dp[j-1][nd]);
            }
            // cout << "\n";
            // for(int j=0;j<=n;j++) cout << dp[i][j] << " ";
            // cout << "\n";
        }
        cout << "Case #" << i << ": " << dp[n][mn[n]] << "\n";
    }
}
