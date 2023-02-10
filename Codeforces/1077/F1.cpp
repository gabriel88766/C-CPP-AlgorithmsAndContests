#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 205;
ll dp[N][N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, x, k;
    cin >> n >> k >> x;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    if(n/k > x){
        cout << -1;
        return 0;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j] = -INF_LL;
        }
    }
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            for(int w=1;w<=k;w++){
                if(i-w >= 0) dp[i][j] = max(dp[i][j], dp[i-w][j-1] + v[i]);
            }
        }
    }
    ll ans = 0;
    for(int i=n-k+1; i<=n;i++) ans = max(ans, dp[i][x]);
    cout << ans;
}
