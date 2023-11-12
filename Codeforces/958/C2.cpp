#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
vector<vector<int>> dp(2, vector<int>(20005, INF_INT));
vector<int> ps(20005, 0);
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
         cin >> v[i];   
         v[i] %= p;
         ps[i] = ps[i-1] + v[i];
    }
    for(int i=1;i<=n;i++) dp[0][i] = ps[i] % p;
    for(int i=2;i<=k;i++){
        int best = dp[0][i-1];
        for(int j=i;j<=n;j++){
            dp[1][j] = (ps[j] - best) % p + best;
            best = max(best, dp[0][j]);
        }
        dp[0] = dp[1];
    }
    cout << dp[1][n] << "\n";
}