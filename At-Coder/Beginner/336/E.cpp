#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


ull dp[16][2][130][130][130];
ull pd[16][130];

void init(){
    ull aux = 1;
    for(int i=0;i<=15;i++){
        for(ll j=1;j<=126;j++){
            pd[i][j] = aux % j;
        }
        aux *= 10;
    }
}

void query(string ss) {
    int n = ss.size();
    //memset(dp, 0, sizeof(dp)); //if more than 1 query
    //empty suffixes having sum=0
    for(int i=1;i<=126;i++) dp[n][0][0][i][0] = dp[n][1][0][i][0] = 1;
    for(int i = n-1; i >=0 ; i--) {
        for(ll sdig = 0; sdig <= 126 ; sdig++) {
            for(ll mod = 1; mod <= 126; mod++){
                for(ll r = 0; r < mod; r++){
                    for(ll d = 0; d <= ss[i] - '0' ; d++) { 
                        if(sdig + d > 126) break;
                        dp[i][1][sdig + d][mod][(r + d*pd[n-1-i][mod]) % mod] +=   (d == ss[i]-'0') ? dp[i+1][1][sdig][mod][r] : dp[i+1][0][sdig][mod][r];
                    
                    }
                    for(int d = 0; d < 10 ; d++) {
                        if(sdig + d > 126) break;
                        dp[i][0][sdig + d][mod][(r+d*pd[n-1-i][mod]) % mod] += dp[i+1][0][sdig][mod][r];
                    }
                }
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    string n;
    cin >> n;
    query(n);
    ull ans = 0;
    for(int i=1;i<=126;i++) ans += dp[0][1][i][i][0];
    cout << ans << "\n";
}
