#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[20][2];

ll query(string ss) {
    int n = ss.size();
    memset(dp, 0, sizeof(dp)); 
    dp[n][0] = 1;
    dp[n][1] = 1;
 
    for(int i = n-1; i >=0 ; i--) {
        for(int tight = 0; tight < 2 ; tight++) {
            if(tight) {
                for(int d = 0; d <= ss[i] - '0' ; d++) { 
                    if(d == 4) continue;
                    dp[i][1] +=   (d == ss[i]-'0') ? dp[i+1][1] : dp[i+1][0];
                }
            }
            else {
                for(int d = 0; d < 10 ; d++) {
                    if(d == 4) continue;
                    dp[i][0] += dp[i+1][0];
                }
            }
            
        }
    }
    return dp[0][1]-1;
}

string toStr(ll n){
    string ans;
    while(n){
        char c = ('0' + n%10);
        ans += c;
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll k;
        cin >> k;
        ll lo = 0, hi = 1e18, mid;
        while(lo != hi){
            mid = (lo+hi)/2;
            string s = toStr(mid);
            if(query(s) < k) lo = mid+1;
            else hi = mid;
        }
        cout << lo << "\n";
    }
}
