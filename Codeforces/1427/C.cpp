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
    int r, n;
    cin >> r >> n;
    vector<int> t(n+1), x(n+1), y(n+1), dp(n+1, -1);
    x[0] = y[0] = 1;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> t[i] >> x[i] >> y[i];
        for(int j=max(0, i-4*r); j < i; j++){
            if(dp[j] == -1) continue;
            int d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            if(d <= t[i] - t[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
}
