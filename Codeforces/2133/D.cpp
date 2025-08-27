#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
            int x;
            dp[i][0] = dp[i][1] = INF_LL;
            cin >> x;
            if(i == 1){
                dp[i][1] = x;
            }else{
                dp[i][1] = x + min(dp[i-1][0], dp[i-1][1]);
                dp[i][0] = min(x-1 + dp[i-1][0], max(x - i + 1, 0) + dp[i-1][1]);
            }
        }
        cout << min(dp[n][0], dp[n][1]) << "\n";
    }
}
