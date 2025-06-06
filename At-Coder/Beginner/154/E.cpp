#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ull dp[101][2][5];

void query(string ss) {
    int n = ss.size();
    //memset(dp, 0, sizeof(dp)); //if more than 1 query
    //empty suffixes having sum=0
    dp[n][0][0] = 1;
    dp[n][1][0] = 1;
 
    for(int i = n-1; i >=0 ; i--) {
        for(int x = 0; x <= 3 ; x++) {
            for(int d = 0; d <= ss[i] - '0' ; d++) { //10*k to avoid overflow and negatives.
                dp[i][1][x + (d != 0 ? 1 : 0)] +=   (d == ss[i]-'0') ? dp[i+1][1][x] : dp[i+1][0][x];
            }
            for(int d = 0; d < 10 ; d++) {
                dp[i][0][x + (d != 0 ? 1 : 0)] += dp[i+1][0][x];
            }
            
        }
        
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string n;
    int k;
    cin >> n >> k;
    query(n);
    cout << dp[0][1][k] << "\n";
}
