#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-6; 
using namespace std;

struct Fraction{
    ll a, b;
    bool operator< (const Fraction &f) const {
        __int128 x1 = a, x2 = b;
        x1 *= f.b, x2 *= f.a;
        return x1 < x2;
    }
};
const int N = 1e5+2;

Fraction dp[2][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    double lo = 0, hi = 1e9;
    while(hi - lo >= EPS){
        //avg
        double mid = (lo + hi)/2;
        vector<vector<double>> dp(n+1, vector<double>(2));
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            if(i == 1){
                dp[i][0] = dp[i-1][1] + v[i] - mid;
                dp[i][1] = dp[i-1][0];
            }else{
                dp[i][0] = max(dp[i-1][0] + v[i] - mid, dp[i-1][1] + v[i] - mid);
                dp[i][1] = dp[i-1][0];
            }
        }
        if(max(dp[n][0], dp[n][1]) >= 0) lo = mid;
        else hi = mid;
    }
    double ans1 = lo;
    ll l = 0, h = 1e9;
    while(l != h){
        //avg
        ll mid = l + (h - l + 1)/2;
        vector<vector<int>> dp(n+1, vector<int>(2));
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            int cur = v[i] >= mid ? 1 : -1;
            if(i == 1){
                dp[i][0] = dp[i-1][0] + cur;
                dp[i][1] = dp[i-1][0];
            }else{
                dp[i][0] = max(dp[i-1][0] + cur, dp[i-1][1] + cur);
                dp[i][1] = dp[i-1][0];
            }
        }
        if(max(dp[n][0], dp[n][1]) >= 1) l = mid;
        else h = mid -1;
    }
    long long ans2 = l;
    cout << setprecision(10) << ans1 << " "; 
    cout << ans2 << "\n";
}
