#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> v(n+1);
    vector<ll> c(k+1), h(k+1);
    vector<ll> ps(n+1, 0);
    vector<ll> dp(n+1, INF_LL);
    

    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=k;i++) cin >> c[i];
    for(int i=1;i<=k;i++) cin >> h[i];

    for(int i=1;i<=n;i++) ps[i] = ps[i-1] + (v[i] == v[i-1] ? h[v[i]] : c[v[i]]);

    dp[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            ll cur = min(dp[j] + ps[i] - ps[j] + (v[j+1] == v[j] ? c[v[j]] - h[v[j]] : 0), j+1 < i ? dp[j] + ps[i-1] - ps[j]\
            + (v[j+1] == v[j] ? c[v[j]] - h[v[j]] : 0) + (v[j] == v[i] ?  h[v[i]] : c[v[i]]) : INF_LL);
            dp[i] = min(dp[i], cur);
        }
        dp[i] = min(dp[i], dp[i-1] + (v[i] == v[i-1] ? h[v[i]] : c[v[i]]));
        cout << dp[i] << " ";
    }
    // cout << dp[n] << "\n";
    
    
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
