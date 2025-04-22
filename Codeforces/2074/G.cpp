#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 405;
ll dp[N][N];
ll aux[N];
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
        vector<ll> a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++) aux[i] = 0;
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    aux[k] = max(aux[k], a[i] * a[j] * a[k] + dp[i+1][j-1] + dp[j+1][k-1]);
                }
            }
            for(int j=i;j<=n;j++){
               dp[i][j] = dp[i+1][j];
                for(int k=i+2;k<=j;k++){
                    dp[i][j] = max(dp[i][j], aux[k] + dp[k+1][j]);
                }
            }
        }
        cout << dp[1][n] << "\n";
    }
}
