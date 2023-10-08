#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+9;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ull dp[129][129][1001];
int pot_2[129];
int n, k;

void init(){
    pot_2[0] = 1 % k;
    for(int i=1;i<=128;i++){
        pot_2[i] = (2 * pot_2[i-1]) % k;
    }
}
int query() {
    //memset(dp, 0, sizeof(dp)); //if more than 1 query
    //empty suffixes having sum=0
    dp[0][0][0] = 1;
    for(int i = 1; i <= n ; i++) {
        for(int qt = 0; qt <= i; qt++){
            for(int sum = 0; sum < k ; sum++) {
                for(int d = 0; d <= 1; d++) {
                    if(qt == 0 && d == 1) continue;
                    //actually 2^(i-1)
                    if(d == 1){
                        int nxt = (sum +  pot_2[i-1]) % k;
                        dp[i][qt][nxt] = (dp[i][qt][nxt] + dp[i-1][qt-1][sum]) % MOD;
                    }else{
                        dp[i][qt][sum] = (dp[i][qt][sum] + dp[i-1][qt][sum]) % MOD;
                    }
                    
                }
            }
        }
    }
    ull ans = 0;
    for(ull i=0;i<=n;i++){
        ans = (ans + dp[n][i][0] * i) % MOD;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> k >> n;
    init();
    // n bits, k mod
    cout << query() << "\n";
}
