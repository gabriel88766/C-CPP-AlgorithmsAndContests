#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> c(n), h(n);
        int sh = 0;
        for(int i=0;i<n;i++){
            cin >> c[i] >> h[i];
            sh += h[i];
        }
        vector<ll> dp(sh + 1, INF_LL);
        dp[0] = 0;
        for(int i=0;i<n;i++){
            ll m = x;
            m *= i;
            for(int j=sh;j>=h[i];j--){
                ll w = dp[j - h[i]] + c[i];
                if(w <= m) dp[j] = min(dp[j], w);
            }
        }
        ll ans = 0;
        for(int i=0;i<=sh;i++) if(dp[i] != INF_LL) ans = i;
        cout << ans << "\n";
    }
}
