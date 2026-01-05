#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 205;
ll dp[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    string s, t;
    cin >> n >> k >> s >> t;
    if(t[0] == t[1]){
        int q0 = 0;
        for(int j=0;j<n;j++){
            if(s[j] == t[0]) q0++;
        }
        q0 += min(k, n - q0);
        cout << ((q0)*(q0-1))/2 << "\n";
    }else{
        //i is the quantity of moves, j is the quantity of t[0] so far
        memset(dp, 192, sizeof(dp));
        dp[0][0] = 0;
        for(auto c : s){
            for(int i=k;i>=0;i--){
                for(int j=n;j>=0;j--){
                    if(i != k){
                        //allow change
                        //change to t[0]
                        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
                        //change to t[1]
                        dp[i+1][j] = max(dp[i+1][j], dp[i][j] + j);
                    }
                    if(c == t[0]) dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
                    if(c == t[1]) dp[i][j] += j;
                }
            }
        }
        ll ans = 0;
        for(int i=0;i<=k;i++){
            for(int j=0;j<=n;j++){
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << "\n";
    }
}
