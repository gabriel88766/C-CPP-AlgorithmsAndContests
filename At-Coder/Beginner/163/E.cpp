#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[2005][2005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = -INF_LL;
    dp[0][0] = 0;
    sort(v.begin(), v.end(), greater<pair<ll, ll>>());
    //type1 (pos - j) * val
    //type2 (n - (in-j-1) - pos) * val
    for(ll i=0;i<n;i++){
        ll in = i+1;
        for(ll j=0;j<=in;j++){
            if(j && j != in) dp[in][j] = max(dp[i][j] + (n + j - i - v[i].second) * v[i].first, dp[i][j-1] + (v[i].second - j) * v[i].first);
            else if(j == 0) dp[in][j] = dp[i][j] + (n + j - i - v[i].second) * v[i].first;
            else dp[in][j] = dp[i][j-1] + (v[i].second - j) * v[i].first;
        }
    }
    ll ans = -INF_LL;
    for(int i=0;i<=n;i++) ans = max(ans, dp[n][i]);
    cout << ans << "\n";
}
