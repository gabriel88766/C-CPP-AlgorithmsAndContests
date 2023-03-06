#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll dp[N][2];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> f(n), b(n);
    for(int i=0;i<n;i++){
        cin >> f[i] >> b[i];
    }
    dp[0][0] = dp[0][1] = 1;
    for(int i=1;i<n;i++){
        if(f[i] != f[i-1]) dp[i][0] += dp[i-1][0];
        if(f[i] != b[i-1]) dp[i][0] += dp[i-1][1];
        if(b[i] != f[i-1]) dp[i][1] += dp[i-1][0];
        if(b[i] != b[i-1]) dp[i][1] += dp[i-1][1];
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }
    cout << (dp[n-1][0] + dp[n-1][1])%MOD;
}
