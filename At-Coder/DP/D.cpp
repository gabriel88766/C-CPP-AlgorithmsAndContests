//Knapsack I
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
ll dp[105][N]; //max value with i items allowed and at most j weight

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, W;
    cin >> n >> W;
    vector<ll> vals(n+1), w(n+1);
    for(int i=1;i<=n;i++){
        ll a,b;
        cin >> w[i] >> vals[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1; j<=W;j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(j >= w[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + vals[i]);
        }
    }
    cout << dp[n][W];

}
