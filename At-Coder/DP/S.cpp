#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ull dp[10001][2][101];

int query(string ss, int k) {
    int n = ss.size();
 
    //empty suffixes having sum=0
    dp[n][0][0] = 1;
    dp[n][1][0] = 1;
 
    for(int i = n-1; i >=0 ; i--) {
        for(int tight = 0; tight < 2 ; tight++) {
            for(int sum = 0; sum < k ; sum++) {
                if(tight) {
                    for(int d = 0; d <= ss[i] - '0' ; d++) {
                        dp[i][1][sum] +=   (d == ss[i]-'0') ? dp[i+1][1][(sum-d + 10*k)%k] : dp[i+1][0][(sum-d + 10*k)%k];
                        dp[i][1][sum] %= MOD;
                    }
                }
                else {
                    for(int d = 0; d < 10 ; d++) {
                        dp[i][0][sum] = dp[i][0][sum] + dp[i+1][0][(sum-d + 10*k)%k];
                        dp[i][0][sum] %= MOD;
                    }
                }
            }
        }
    }
    return dp[0][1][0];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s;
    ll k;
    cin >> s >> k;
    ull ans = query(s,k);
    cout << (ans > 0 ? ans-1 : MOD-1) ;
    
}
