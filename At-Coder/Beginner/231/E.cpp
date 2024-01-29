#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[61][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    if(n == 1){
        cout << x << "\n";
        return 0;
    }
    vector<ll> div(n);
    ll aux = x;
    for(int i=n-1;i>=0;i--){
        if(v[i] <= aux){
            div[i] = aux / v[i];
            aux -= div[i] * v[i];
        }
    }
    for(int i=0;i<n-1;i++){
        ll opt1 = div[i];
        ll opt2 = v[i+1]/v[i] - opt1;
        if(i == 0){
            dp[i][0] = opt1;
            dp[i][1] = opt2;
        }else{
            dp[i][0] = min(dp[i-1][0] + opt1, dp[i-1][1] + opt1 + 1);
            dp[i][1] = min(dp[i-1][0] + opt2, dp[i-1][1] + opt2 - 1);
        }
    }
    ll ans = min(dp[n-2][0] + div[n-1], dp[n-2][1] + div[n-1] + 1);
    cout << ans << "\n";
}
