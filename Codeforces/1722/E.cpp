#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[1002][1002];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<n;i++){
            ll a,b;
            cin >> a >> b;
            for(int j=(b+1);j<=1001;j++){
                dp[a+1][j] += a*b;
            }
        }
        for(int i=2;i<=1001;i++){
            for(int j=1;j<=1001;j++){
                dp[i][j] += dp[i-1][j];
            }
        }
        for(int i=1;i<=q;i++){
            int h1,h2,w1,w2;
            cin >> h1 >> w1 >> h2 >> w2;
            cout << dp[h2][w2] + dp[h1+1][w1+1] - dp[h1+1][w2] - dp[h2][w1+1] << "\n";
        }
        
    }
}
