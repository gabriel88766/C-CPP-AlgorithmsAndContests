#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

double dp[105];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(dp[i-1] > j) dp[i] += dp[i-1]/6;
            else dp[i] += j/6.0;
        }
    }


    cout << fixed << setprecision(10) << dp[n] << "\n";
}
