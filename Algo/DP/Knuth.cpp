#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
int opt[N][N];
ll dp[N][N];
ll ps[N];

void knuth(int n){
    memset(dp, 63, sizeof(dp));
    for(int i=1;i<=n;i++) opt[i][i] = i, dp[i][i] = 0;
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            for(int k=opt[i][j-1]; k <= opt[i+1][j]; k++){
                if(dp[i][j] > dp[i][k] + dp[k+1][j] + ps[j] - ps[i-1]){
                    dp[i][j] = dp[i][k] + dp[k+1][j] + ps[j] - ps[i-1];
                    opt[i][j] = k;
                }
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
         cin >> ps[i];
         ps[i] += ps[i-1];
    }
    knuth(n);
    cout << dp[1][n] << "\n";
}
