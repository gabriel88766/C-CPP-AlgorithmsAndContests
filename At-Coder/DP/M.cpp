#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[105][100005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n+1);
    vector<ll> ps(k+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    dp[0][k] = 1;
    for(int i = 1; i<= n;i++){
        ps[0] = dp[i-1][0];
        for(int j=1;j<=k;j++) ps[j] = ps[j-1] + dp[i-1][j];
        for(int j=0;j<=k;j++){
            dp[i][j] = ps[min(k, j+v[i])] - (j > 0 ? ps[j-1] : 0);
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][0];
}
