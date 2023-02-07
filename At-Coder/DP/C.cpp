#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int dp[N][3];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a;
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b;
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c;
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
}
