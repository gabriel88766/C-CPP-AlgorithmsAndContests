#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

double dp[405][205][205];
double avg[205];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[0][0][0] = 1;
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<2*n;i++){
        for(int j=0;j<l;j++){
            for(int k=0;k<n;k++){
                if(dp[i][j][k] == 0.0) continue;
                double p1 = (i - 2*k);
                p1 /= (2 * n - i);
                dp[i+1][j][k+1] += p1 * dp[i][j][k];
                double p2 = 1.0 / (2 * n - i - 1);
                double p3 = (i - 2*k);
                p3 /= (2 * n - i - 1);
                double p4 = (2*n - i - 1 - (i - 2 * k) - 1);
                p4 /= (2 * n - i - 1);
                dp[i+2][j][k+1] += (1-p1) * p2 * dp[i][j][k]; //lucky!
                dp[i+2][j+1][j == l-1 ? k : k+1] += (1 - p1) * p3 * dp[i][j][k]; //One more pair, good, except if l = j+1
                dp[i+2][j+1][k] += (1 - p1) * p4 * dp[i][j][k]; //bad.
            }
        }
    }
    double sum = 0;
    for(int i=0;i<n;i++){
        sum += v[i];
    }
    double ans = 0;
    for(int i=1;i<=n;i++){
        double px = 0;
        if(i == n){
            for(int j=0;j<l;j++) px += dp[2*n][j][n];
        }else{
            for(int j=0;j<=2*n;j++) px += dp[j][l][i];
        }
        ans += (sum * i)/n * px;
    }
    cout << fixed << setprecision(10) << ans << "\n";
}
