#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ull dp[20][2][20];

int query(string ss) {
    if(ss == "0") return 0;
    int n = ss.size();
    memset(dp, 0, sizeof(dp));
    //empty suffixes having sum=0
    dp[n][0][0] = 1;
    dp[n][1][0] = 1;
 
    for(int i = n-1; i >=0 ; i--) {
        for(int tight = 0; tight < 2 ; tight++) {
            for(int qt = 0; qt < 20 ; qt++) {
                if(tight) {
                    for(int d = 0; d <= ss[i] - '0' ; d++) {
                       if(d && qt) dp[i][1][qt] +=  (d == ss[i]-'0') ? dp[i+1][1][qt-1] : dp[i+1][0][qt-1];
                       else if(!d) dp[i][1][qt] += (d == ss[i]-'0') ? dp[i+1][1][qt] : dp[i+1][0][qt];
                    }
                }
                else {
                    for(int d = 0; d < 10 ; d++) {
                        if(d && qt) dp[i][0][qt] += dp[i+1][0][qt-1];
                        else if(!d) dp[i][0][qt] += dp[i+1][0][qt];
                    }
                }
            }
        }
    }
    return dp[0][1][1] + dp[0][1][2] + dp[0][1][3];
}

string itoa(ll a){
    string ans;
    while(a){
        char cur = (a % 10) + '0';
        ans += cur;
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
    ll a, b;
    ll t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        string sa = itoa(a-1);
        string sb = itoa(b);
        ull ans = query(sb) - query(sa);// - query(sa);
        cout << ans << "\n";
    }
    
    
}
