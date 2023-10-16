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
        vector<int> v(n+1), dp(n+1, 0);
        for(int i=1;i<=n;i++) dp[i] = i;
        int cur = 0;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            cur = min(cur+1, dp[i-1]);
            if(i + v[i] <= n){
                dp[i+v[i]] = min(dp[i+v[i]], cur);
            }
            
        }
        //for(auto x : dp) cout << x << " ";
        //cout << "\n";
        int ans = n;
        for(int i=1;i<=n;i++){
            ans = min(ans, dp[i] + n-i);
        }
        cout << ans << "\n";
    }
}
