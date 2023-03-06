#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ull dp[20][2][11]; //current digit, tight or not, digit

ull query(string ss) {
    int n = ss.size();
    
    memset(dp, 0, sizeof(dp));
    dp[n][0][0] = 1;
    dp[n][1][0] = 1;
 
    for(int i = n-1; i >=0 ; i--) {
        for(int tight = 0; tight < 2 ; tight++) {
            if(tight) {
                for(int d = 0; d <= ss[i] - '0' ; d++) {
                    for(int v = 0; v <= 9; v++){
                        if(d != v || i == (n-1)){
                            dp[i][1][d] += (d == ss[i]-'0') ? dp[i+1][1][v] : dp[i+1][0][v];
                        }
                    }
                }
            }
            else {
                for(int d = 0; d <= 9 ; d++) { 
                    for(int v = 0; v <= 9; v++){
                        if(d != v || i == (n-1)){
                            dp[i][0][d] += dp[i+1][0][v];
                        }
                    }
                }
            }
        }
    }
    ull ans = 0;
    for(int i=1;i<=(ss[0]-'0');i++) ans += dp[0][1][i];
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=9;j++){
            ans += dp[i][0][j];
        }
    }
    return ans+1;
}

string myitoa(ull a){
    string ans;
    while(a){
        ans += (char)('0' + a%10);
        a /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string t;
    ull a;
    cin >> a >> t;
    if(a == 0){
        cout << query(t) << "\n";
        return 0;
    }
    a--;
    ull ans1 = query(myitoa(a));
    ull ans2 = query(t);
    cout << ans2 - ans1 << "\n";
    
}
