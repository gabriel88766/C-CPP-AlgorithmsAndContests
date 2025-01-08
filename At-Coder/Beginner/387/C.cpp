#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[21][2][10];

ll solve(string ss) {
    if(ss.size() <= 2){
        ll ans = 0;
        for(int i=10;i<=stoi(ss);i++){
            int d1 = i / 10;
            int d2 = i % 10;
            if(d1 > d2) ans++;
        }
        return ans;
    }
    int n = ss.size();
    memset(dp, 0, sizeof(dp)); //if more than 1 query
    //empty suffixes having sum=0
    dp[n][0][0] = 1;
    dp[n][1][0] = 1;
    
    for(int i = n-1; i >=0 ; i--) {
        for(int d = 0; d <= ss[i] - '0' ; d++) { //10*k to avoid overflow and negatives.
            for(int md=0;md<10;md++){
                dp[i][1][max(d, md)] += (d == ss[i]-'0') ? dp[i+1][1][md] : dp[i+1][0][md];
            }
        }
        for(int d = 0; d < 10 ; d++) {
            for(int md=0;md<10;md++){
                dp[i][0][max(d, md)] += dp[i+1][0][md];
            }
        }   
    }
    ll ans = 0;
    for(int i=2;i<=n-1;i++){
        for(int j=1;j<=9;j++){
            for(int k=0;k<j;k++){
                ans += dp[i][0][k];
            }
        }
    }
    //now i = 1
    for(int j=1;j<ss[0]-'0';j++){
        for(int k=0;k<j;k++){
            ans += dp[1][0][k];
        }
    }
    for(int k=0;k<ss[0]-'0';k++){
        ans += dp[1][1][k];
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll l, r;
    cin >> l >> r;
    cout << solve(to_string(r)) - solve(to_string(l-1)) << "\n";
}
