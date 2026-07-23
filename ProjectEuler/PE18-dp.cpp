#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string data_ = "75 \
95 64 \
17 47 82 \
18 35 87 10 \
20 04 82 47 65 \
19 01 23 75 03 34 \
88 02 77 73 07 63 67 \
99 65 04 28 06 16 70 92 \
41 41 26 56 83 40 80 70 33 \
41 48 72 33 47 32 37 16 94 29 \
53 71 44 65 25 43 91 52 97 51 14 \
70 11 33 28 77 73 17 78 39 68 17 57 \
91 71 52 38 17 14 91 43 58 50 27 29 48 \
63 66 04 68 89 53 67 30 73 16 69 87 40 31 \
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";
ll dp[100][100];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    istringstream iss(data_);
    iss >> dp[0][0];
    for(int i=1;i<=15;i++){
        for(int j=0;j<=i;j++){
            iss >> dp[i][j];
            if(j == 0) dp[i][j] += dp[i-1][j];
            else dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    ll ans = 0;
    for(int j=0;j<=15;j++) ans = max(ans, dp[15][j]);
    cout << ans << "\n";
}
