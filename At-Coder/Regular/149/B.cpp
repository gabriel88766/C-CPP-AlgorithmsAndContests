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
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].first;
    for(int i=0;i<n;i++) cin >> v[i].second;
    vector<int> dp(n+2, INF_INT);
    dp[0] = 0;
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i=0;i<n;i++){
        int ind = lower_bound(dp.begin(), dp.end(), v[i].second) - dp.begin();
        dp[ind] = v[i].second;
        ans = max(ans, ind);
    }
    ans += n;
    cout << ans << "\n";
}
