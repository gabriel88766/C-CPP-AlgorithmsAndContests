#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[200005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    
    for(int i=1;i<=200000;i++){
        for(int j=1;i*j<=200000;j++){
            dp[i*j]++;
        }
    }
    ll n;
    cin >> n;
    ll ans = 0;
    for(int i=1;i<n;i++){
        ans += dp[i] * dp[n-i];
    }
    cout << ans << "\n";
}
