#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
ll sum[N], v[N], dp[N];
int n;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=(n-1);i++) sum[i] = sum[i-1] + v[(i+1)/2];

    for(int i=1;i<=(n-1);i++){
        dp[i] = sum[i];
        for(int j=1;j<(i-1);j++){
            dp[i] = max(dp[i], dp[j] + dp[i-j-1]);
        }
    }
    cout << dp[n-1];
}
