#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll dp[N][2];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        ll n, s;
        cin >> n >> s;
        vector<ll> a;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            a.push_back(aux);
        }
        vector<pair<ll,ll>> xs;
        xs.push_back({0,0});
        for(int i=1;i<(n-1);i++){
            if(a[i] >= s) {
                if(s < (a[i] - s))   xs.push_back({s, a[i] - s});
                else xs.push_back({a[i]-s,s});
            }else{
                xs.push_back({0, a[i]});
            }
        }
        dp[0][0] = a[0] * xs[1].first;
        dp[0][1] = a[0] * xs[1].second;

        for(int i=1;i<(xs.size()-1);i++){
            dp[i][0] = min(dp[i-1][0] + xs[i].second * xs[i+1].first, dp[i-1][1] + xs[i].first * xs[i+1].first);
            dp[i][1] = min(dp[i-1][0] + xs[i].second * xs[i+1].second, dp[i-1][1] + xs[i].first * xs[i+1].second);
            
        }
        dp[n-2][0] = dp[n-3][0] + xs[n-2].second * a[n-1];
        dp[n-2][1] = dp[n-3][1] + xs[n-2].first * a[n-1];
        cout << min(dp[n-2][0], dp[n-2][1]) << "\n";
        for(int i=0;i<=n;i++) dp[i][0] = dp[i][1] = 0;
    }
}
 