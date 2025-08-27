#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
ll dp[N], ndp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        for(int i=0;i<=n;i++) dp[i] = 0;
        dp[0] = 1;
        for(int i=n;i>=1;i--){
            for(int j=0;j<=n;j++) ndp[j] = 0;
            for(int j=0;j<=n;j++){
                //this number isn't present
                ndp[j+1] += dp[j];
                //this number is present
                ndp[j] += dp[j] * i * (j+1);
            }
            for(int j=0;j<=n;j++) dp[j] = ndp[j] % m;
        }
        ll ans = 0;
        for(int j=0;j<=n;j++) ans = (ans + dp[j]) % m;
        cout << ans << "\n";
    }
}
