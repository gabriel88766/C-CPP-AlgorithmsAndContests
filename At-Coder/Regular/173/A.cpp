#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


ll dp[20][2][12];

ll query(ll num) {
    string ss = to_string(num);
    int n = ss.size();
    memset(dp, 0, sizeof(dp)); 
    //empty suffixes having sum=0
    for(int j=0;j<=9;j++) dp[n-1][0][j] = 1;
    for(int j=0;j<=ss[n-1]-'0';j++) dp[n-1][1][j] = 1;
 
    for(int i = n-2; i >=0 ; i--) {
        for(int d = 0; d <= ss[i] - '0' ; d++) { //10*k to avoid overflow and negatives.
            if(d == ss[i] - '0'){
                for(int j=0;j<=9;j++){
                    if(d != j) dp[i][1][d] += dp[i+1][1][j];
                }
            }else{
                for(int j=0;j<=9;j++){
                    if(d != j) dp[i][1][d] += dp[i+1][0][j];
                }
            }
        }
        for(int d = 0; d <= 9 ; d++) {
            for(int j=0;j <= 9;j++){
                if(d != j) dp[i][0][d] += dp[i+1][0][j];
            }
        }
    }
    ll ans = 0;
    for(int i=0;i<=n-1;i++){
        for(int j=1;j<=9;j++){
            if(i == 0) ans += dp[i][1][j];
            else ans += dp[i][0][j];
        }
    }
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
        ll lo = 1, hi = 1e16;
        while(lo != hi){
            ll mid = lo + (hi - lo) / 2;
            if(query(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
}
