#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int dp[N][2];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1, 0);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(i >= 2){
            if(v[i] > v[i-2]) dp[i][1] = dp[i-2][0] + 1;
            if(v[i] > v[i-1]) dp[i][1] = max(dp[i][1], dp[i-1][1] + 1);
        }
        dp[i][0] = 1;
        if(v[i] > v[i-1]) dp[i][0] = dp[i-1][0] + 1;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }
    cout << ans << "\n";
}
