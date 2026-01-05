#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
int dp[N], odp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int ans = INF_INT;
        vector<vector<int>> oc(n+1);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            oc[x].push_back(i);
        }
        for(int i = 0;i<=n;i++){
            dp[i] = odp[i] = 0;
        }
        for(int i=1;i<=n;i++){
            for(auto x : oc[i]){
                if(x < i) continue;
                int mx = 0;
                for(int j=0;j<=x-i;j++) mx = max(mx, odp[j]);
                dp[x - i] = mx + 1;
                if(dp[x - i] >= k) ans = min(ans, x-i);
            }
            for(int j=0;j<=n;j++) odp[j] = dp[j];
        }
        if(ans == INF_INT) cout << "-1\n";
        else cout << ans << "\n";
    }
}
