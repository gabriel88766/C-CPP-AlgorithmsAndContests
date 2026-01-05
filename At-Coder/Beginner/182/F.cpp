#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[2][60];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<ll> nx;
    vector<ll> mx;
    auto ax = x;
    for(int i=0;i<n;i++){
        if(i != n-1){
            ll cx = ax % v[i+1];
            nx.push_back(cx / v[i]);
            mx.push_back(v[i+1] / v[i]);
        }   
    }
    ll ans = 1;
    for(int i = nx.size()-1;i>=0;i--){
        if(nx[i] != 0){
            dp[0][i] = 1;
            bool c0 = false;
            for(int j=i+1;j<nx.size();j++){
                if(c0) dp[0][i] += dp[0][j];
                else dp[0][i] += dp[1][j];
                if(dp[1][j] != 0) c0 = true;
            }
        }
        if(nx[i] + 1 != mx[i]){
            dp[1][i] = 1;
            bool c0 = false;
            for(int j=i+1;j<nx.size();j++){
                if(c0) dp[1][i] += dp[0][j];
                else dp[1][i] += dp[1][j];
                if(dp[1][j] != 0) c0 = true;
            }
        }
        ans += dp[0][i];
    }
    // for(auto x : nx) cout << x << " ";
    // cout << "\n";
    // cout << pos + neg << "\n";
    cout << ans << "\n";
}
