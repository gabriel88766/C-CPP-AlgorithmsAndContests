#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
long double dp[N][N], aux[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    vector<long double> vc;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        long double p;
        cin >> p;
        vc.push_back(p);
    }
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = 0;
    
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            dp[i][j] = dp[i-1][j-1] * vc[i-1] + dp[i-1][j] * (1. - vc[i-1]); 
        }
    }
    long double ans = 0;
    int half = n/2+1;
    for(int i=half; i<=n;i++){
        ans += dp[n][i];
    }


    cout << fixed << setprecision(15) << ans;
}
