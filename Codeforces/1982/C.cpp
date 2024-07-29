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
    int t;
    cin >> t;
    while(t--){
        ll n, l, r;
        cin >> n >> l >> r;
        vector<ll> a(n+1), ps(n+1);
        vector<ll> dp(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        
        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1];
            ps[i] = ps[i-1] + a[i];
            auto it = lower_bound(ps.begin(), ps.begin() + i, ps[i] - l+1);
            if(it != ps.begin()){
                --it;
                if(ps[i] - *it <= r){
                    int d = it - ps.begin();
                    dp[i] = max(dp[i], dp[d] + 1);
                }
            }
        }
        cout << dp[n] << "\n";
    }
}
