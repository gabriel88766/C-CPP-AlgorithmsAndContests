#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1000005;
ll dp[N][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    s = " " + s;
    dp[0][0] = 0;
    dp[0][1] = INF_LL;
    for(int i=1;i<s.size();i++){
        int dg = s[i] - '0';
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + dg;
        dp[i][1] = min(dp[i-1][0] + 11 - dg, dp[i-1][1] + 9 - dg);
    }
    cout << min(dp[s.size()-1][0], dp[s.size()-1][1]) << "\n";
}
