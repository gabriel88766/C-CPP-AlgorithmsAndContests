#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
ll dp[N][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x, y;
        cin >> x >> y;
        if(x == 0){
            dp[i][0] = max({dp[i-1][1] + y, dp[i-1][0], dp[i-1][0] + y});
            dp[i][1] = dp[i-1][1];
        }else{//poison
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + y); 
            dp[i][0] = dp[i-1][0];
        }
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";
}
