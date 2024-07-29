#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


int dp[201][201][201];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=0;i<=200;i++){
        for(int j=0;j<=200;j++){
            for(int k=0;k<=200;k++){
                if(i == 0 && j == 0 && k == 0) continue;
                if(i > 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                if(j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                if(k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
                int x = 0;
                if(i % 2) x ^= 1;
                if(j % 2) x ^= 2;
                if(k % 2) x ^= 3;
                if(x == 0){
                    dp[i][j][k]++;
                }
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << dp[a][b][c] + d/2 << "\n";
    }
}
