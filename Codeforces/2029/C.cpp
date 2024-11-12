#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
int v[N];
int dp[N][3];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        dp[0][1] = dp[0][2] = -INF_INT;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(v[i] > dp[i-1][0]) dp[i][0] = dp[i-1][0] + 1;
            else if(v[i] == dp[i-1][0]) dp[i][0] = dp[i-1][0];
            else dp[i][0] = dp[i-1][0] - 1;
            if(v[i] > dp[i-1][2]) dp[i][2] = dp[i-1][2] + 1;
            else if(v[i] == dp[i-1][2]) dp[i][2] = dp[i-1][2];
            else dp[i][2] = dp[i-1][2] - 1;
            dp[i][1] = dp[i-1][1];
            dp[i][1] = max(dp[i][1], dp[i-1][0]);
            if(v[i] > dp[i-1][1]) dp[i][2] = max(dp[i][2], dp[i-1][1] + 1);
            else if(v[i] == dp[i-1][1]) dp[i][2] = max(dp[i][2], dp[i-1][1]);
            else dp[i][2] = max(dp[i][2], dp[i-1][1] - 1);
        }
        cout << max(dp[n][1], dp[n][2]) << "\n";
    }
}
