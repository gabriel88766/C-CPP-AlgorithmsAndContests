#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+2;
ll dp[N][2][2];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> a(n+2), b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    memset(dp, 63, sizeof(dp));
    dp[1][1][1] = 0;
    dp[1][0][0] = a[1];
    for(int i=2;i<=n+1;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                //from dp[i-1][j][k]
                for(int dk=0;dk<2;dk++){
                    ll cst = dp[i-1][j][k];
                    if(dk == k) cst += b[i-1];
                    if(dk == 0) cst += a[i];
                    dp[i][j][dk] = min(dp[i][j][dk], cst);
                }
            }
        }
    }    
    cout << min(dp[n+1][1][1], dp[n+1][0][0]) << "\n";
}
