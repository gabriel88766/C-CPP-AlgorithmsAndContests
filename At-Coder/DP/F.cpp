#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
int dp[N][N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s, t;
    cin >> s >> t;
    //LCS
    //axyb abyxb
    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=t.size();j++){
            dp[i][j] = s[i-1] == t[j-1] ? dp[i-1][j-1] + 1 : dp[i-1][j-1];
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }
    string ans;
    int curi = s.size(), curj = t.size();
    while(curi != 0 && curj != 0 && dp[curi][curj] != 0){
        while(dp[curi][curj] == dp[curi][curj-1]) curj--;
        while(dp[curi][curj] == dp[curi-1][curj]) curi--;
        curi--, curj--;
        ans += s[curi];
    }
    reverse(ans.begin(), ans.end());
    cout << ans;

}
