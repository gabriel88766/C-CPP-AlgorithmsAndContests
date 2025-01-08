#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
int dp[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.size(), m = b.size(), nm = c.size();
        a = " " + a;
        b = " " + b;
        c = " " + c;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j] = INF_INT;
            }
        }
        dp[0][0] = 0;
        for(int i=1;i<=nm;i++){
            for(int j=0;j<=i;j++){
                int k = i - j;
                if(j <= n && k <= m){
                    //then this state is possible
                    if(j > 0){
                        if(a[j] == c[i]) dp[j][k] = min(dp[j][k], dp[j-1][k]);
                        else dp[j][k] = min(dp[j][k], dp[j-1][k] + 1);
                    }
                    if(k > 0){
                        if(b[k] == c[i]) dp[j][k] =  min(dp[j][k], dp[j][k-1]);
                        else dp[j][k] =  min(dp[j][k], dp[j][k-1] + 1);
                    }
                }
            }
        }
        cout << dp[n][m] << "\n";
    }
}
