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
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        ll ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans += a[i] * a[i] + a[j] * a[j];
                ans += b[i] * b[i] + b[j] * b[j];
            }
        }
        
        //dp for the best sum 2aiaj 2bibj
        vector<ll> dp(100*n + 1, INF_INT), ndp(100*n + 1);
        ll tts = 0;
        dp[0] = 0;
        for(int i=0;i<n;i++){
            fill(ndp.begin(), ndp.end(), INF_INT);
            for(int j=0;j<=100*i;j++){
                ll sa = j;
                ll sb = tts - j;
                if(dp[j] != INF_INT){
                    ndp[j + a[i]] = min(ndp[j + a[i]], dp[j] + sa * a[i] + sb * b[i]);
                    ndp[j + b[i]] = min(ndp[j + b[i]], dp[j] + sa * b[i] + sb * a[i]);
                }
            }
            tts += a[i] + b[i];
            dp = ndp;
        }
        ans += 2*(*min_element(dp.begin(), dp.end()));
        cout << ans << "\n";
    }
}
