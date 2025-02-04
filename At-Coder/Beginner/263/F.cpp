
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1 << 16;
ll dp[N][17];
ll aux[17];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<(1 << n);i++){
        for(int j=1;j<=n;j++) cin >> dp[i][j];
    }
    for(int i=1;i<=n;i++){
        int jmp = 1 << i;
        for(int j=0;j<(1 << n); j += jmp){
            int sj = jmp / 2;
            for(int k=0;k<i;k++){
                aux[k] = dp[j][k] + dp[j + sj][k];
            }
            for(int k=i;k<=n;k++){
                aux[k] = max(dp[j][i-1] + dp[j + sj][k], dp[j][k] + dp[j + sj][i-1]);
            }
            for(int k=0;k<=n;k++) dp[j][k] = aux[k];
        }
    }
    cout << dp[0][n] << "\n";
}
