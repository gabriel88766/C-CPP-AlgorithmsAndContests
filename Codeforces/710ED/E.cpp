#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e7+3;
ll dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[0] = 0;
    ll n, x, y;
    cin >> n >> x >> y;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1] + x;
        if(!(i % 2)) dp[i] = min(dp[i], dp[i/2] + y);
        else dp[i] = min(dp[i-1] + x, min(dp[i/2] + x + y, dp[i/2+1] + x + y));     
    }
    cout << dp[n];
}
