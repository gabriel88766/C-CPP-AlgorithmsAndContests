#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[1 << 18];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dp, 63, sizeof(dp));
    dp[0] = 0;
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    for(int i=0;i<(1 << n);i++){
        int lb = 0;
        int ca = __builtin_popcount(i);
        for(int j=0;j<n;j++){
            if(!(i & (1 << j))){
                dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + lb * y + abs(b[j] - a[ca]) * x);
                lb++;
            }
        }
    }
    cout << dp[(1 << n) - 1] << "\n";
}
