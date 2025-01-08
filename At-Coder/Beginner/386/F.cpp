#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 500005;
int mid = 25;
int dp[N][50];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int k;
    string s, t;
    cin >> k >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s;
    t = " " + t;
    int gap = m - n;
    if(abs(gap) > k) cout << "No\n";
    else{
        memset(dp, 63, sizeof(dp));
        dp[0][mid] = 0;
        for(int i=mid;i<=mid+k;i++) dp[0][i] = dp[0][mid] + i-mid;
        for(int i=1;i<=n;i++){
            for(int j=max(0, i-k-1); j<=min(m, i+k+1); j++){
                int cur = j - i + mid;
                if(s[i] == t[j]) dp[i][cur] = dp[i-1][cur];
                else dp[i][cur] = min({dp[i][cur-1], dp[i-1][cur+1], dp[i-1][cur]}) + 1;
                // cout << dp[i][cur] << " ";
            }
            // cout << "\n";
        }
        // cout << dp[n][mid+gap] << "\n";
        if(dp[n][mid + gap] <= k) cout << "Yes\n";
        else cout << "No\n";
    }
    
}
