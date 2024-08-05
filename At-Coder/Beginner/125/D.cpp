#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[2][100005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    dp[1][1] = -INF_LL;
    dp[0][1] = v[1];
    for(int i=2;i<=n;i++){
        dp[1][i] = max(dp[0][i-1] - v[i] - 2*v[i-1], dp[1][i-1] - v[i] + 2*v[i-1]);
        dp[0][i] = max(dp[0][i-1] + v[i], dp[1][i-1] + v[i]);
    }
    cout << max(dp[0][n], dp[1][n]) << "\n";
}
