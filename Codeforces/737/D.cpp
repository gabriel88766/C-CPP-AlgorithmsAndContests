#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[4005][96][201]; //at most 88, but margin to 95
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    //z >= 1 means player 2 
    //z <= 0 means player 1
    //y means the current k
    //x means a + b = x and a - b = z (player 1 played )
    vector<int> v(n+1), ps(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        ps[i] = ps[i-1] + v[i];
    }
    const int mid = 100;
    for(int i=n;i>=0;i--){
        for(int k=95;k>=1;k--){
            for(int j=0;j<=200;j++){
                int z = j - mid;
                int a = i + z;
                if(a % 2 == 1 || a < 0) continue; //impossible state
                a >>= 1;
                int b = i - a;
                if(b < 0) continue; //impossible state
                if(i + k > n) continue; //final state
                if(z >= 1){
                    //player 2
                    dp[i][k][j] = dp[i + k][k][j - k] - ps[n - b] + ps[n - b - k];
                    if(i + k + 1 <= n) dp[i][k][j] = min(dp[i][k][j], dp[i + k + 1][k + 1][j-k-1] - ps[n-b] + ps[n-b-k-1]);
                }else{
                    //player 1
                    dp[i][k][j] = dp[i + k][k][j + k] + ps[a + k] - ps[a];
                    if(i + k + 1 <= n) dp[i][k][j] = max(dp[i][k][j], dp[i + k + 1][k + 1][j + k + 1] + ps[a + k + 1] - ps[a]);
                }
            }
        }
    }
    cout << dp[0][1][mid] << "\n";
}
