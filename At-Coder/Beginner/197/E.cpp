#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

map<int, vector<int>> mp;
ll dp[2][200005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x, c;
        cin >> x >> c;
        mp[c].push_back(x);
    }
    for(auto &[k, v] : mp){
        sort(v.begin(), v.end());
    }
    dp[0][0] = dp[1][0] = 0;
    int i = 0;
    vector<pair<int,int>> vx;
    vx.push_back({0, 0});
    for(auto [k, v] : mp){
        i++;
        ll mn = v[0];
        ll mx = v.back();
        ll mnb = vx.back().first;
        ll mxb = vx.back().second;
        dp[0][i] = min(dp[0][i-1] + abs(mnb - mx) + abs(mx - mn), dp[1][i-1] + abs(mxb - mx) + abs(mx - mn));
        dp[1][i] = min(dp[0][i-1] + abs(mnb - mn) + abs(mx - mn), dp[1][i-1] + abs(mxb - mn) + abs(mx - mn));
        vx.push_back({mn, mx});
    }
    ll ans = min(abs(vx.back().first) + dp[0][i], abs(vx.back().second) + dp[1][i]);
    cout << ans << "\n";
}

