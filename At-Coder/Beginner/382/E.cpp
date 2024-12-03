#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

double dp[5005];
double dp2[5005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, x;
    cin >> n >> x;
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        double p;
        cin >> p;
        p /= 100;
        for(int j=i;j>=1;j--){
            dp[j] = dp[j] * (1-p) + dp[j-1] * p;
        }
        dp[0] *= (1-p);
    }
    for(int i=1;i<=x;i++){
        dp2[i] = 1;
        for(int j=1;j<=n;j++){
            dp2[i] += dp2[max(i-j, 0)] * dp[j];
        }
        dp2[i] /= (1 - dp[0]);
    }
    cout << fixed << setprecision(15) << dp2[x] << "\n";
}
