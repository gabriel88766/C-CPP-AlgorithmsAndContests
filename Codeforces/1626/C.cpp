#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll sum(int n){
    ll ans = n;
    ans *= (n+1);
    return ans/2;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> h(n+1), k(n+1);
        for(int i=1;i<=n;i++) cin >> k[i];
        for(int i=1;i<=n;i++) cin >> h[i];
        vector<ll> dp(n+1, INF_LL);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                //check if it's ok.
                ll mn = INF_INT;
                for(int u=j+1;u<=i;u++){
                    mn = min(mn, k[u] - h[u]); //minimum place to be "0"
                }
                if(mn >= k[j]){
                    //then it's ok.
                    ll vx = k[i] - mn;
                    dp[i] = min(dp[i], dp[j] + sum(vx));
                }
            }
        }
        cout << dp[n] << "\n";
    }
}
