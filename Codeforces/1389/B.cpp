#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int dp[N][6][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int ans = 0;
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        for(int j=0;j<=z;j++) for(int k=0;k<2;k++) dp[0][j][k] = -INF_INT;
        dp[0][0][0] = v[0];
        for(int i=1;i<=k;i++){
            for(int j=0;j<=z;j++){
                for(int k=0;k<2;k++){
                    dp[i][j][k] = -INF_INT;
                }
            }
            for(int j=0;j<=z;j++){
                for(int k=0;k<2;k++){
                    if(dp[i-1][j][k] != -INF_INT){
                        int x = (i-1) - 2*j;
                        assert(x >= 0);
                        if(k == 0 && x > 0 && j < z){
                            dp[i][j+1][1] = dp[i-1][j][k] + v[x-1];
                        } 
                        dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][k] + v[x+1]);
                    }
                }
            }
        }
        int mx = -INF_INT;
        for(int j=0;j<=z;j++){
            for(int x=0;x<2;x++){
                mx = max(mx, dp[k][j][x]);
            }
        }
        cout << mx << "\n";
    }
}
