#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[122][122];
int dp2[122][122];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dp, 63, sizeof(dp));
    memset(dp2, 63, sizeof(dp2));
    dp[0][0] = 0;
    for(int i=1;i<=22;i++){
        for(int a=120;a>=0;a--){
            for(int b=120;b>=0;b--){
                if(a >= i){
                    dp[a][b] = min(dp[a][b], dp[a-i][b] + (1 << i));
                }
                if(b >= i){
                    dp[a][b] = min(dp[a][b], dp[a][b-i] + (1 << i));
                }
            }
        }
    }

    //OH NO, n^4!! (optimize)
    for(int i=120;i>=0;i--){
        for(int j=120;j>=0;j--){
            dp2[i][j] = dp[i][j];
            dp2[i][j] = min({dp2[i][j], dp2[i+1][j], dp2[i][j+1]});
        }
    }

    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        int c1 = 0, c2 = 0;
        while(a != b){
            if(a > b){
                a >>= 1;
                c1++;
            }else{
                b >>= 1;
                c2++;
            }
        }
        int c3 = 0;
        while(a){
            a >>= 1;
            c3++;
        }
        int ans = dp[c1][c2];
        for(int i=1;i<c3;i++){
            ans = min(ans, dp[c1+i][c2+i]);
        }
        ans = min(ans, dp2[c1+c3][c2+c3]);
        cout << ans << "\n";
    }
}
