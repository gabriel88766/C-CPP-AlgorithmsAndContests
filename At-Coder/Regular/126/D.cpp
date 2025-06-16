#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 205;
const int K = 1 << 16;
int v[N];
int dp[K];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        v[i]--;
    }

    for(int j=0;j<(1 << k); j++) dp[j] = INF_INT; //means impossible state
    int ans = INF_INT;
    for(int i=1;i<=n;i++){
        dp[0] = 0;
        for(int j=0;j<(1 << k); j++){
            if(j & (1 << v[i])) continue;
            //need to get how many bits are greater than v[i]
            int d = j | (1 << v[i]);
            int cnt = 0;
            for(int x=v[i]+1;x<k;x++) if(j & (1 << x)) cnt++;

            dp[d] = min(dp[j] + cnt, dp[d] + min(k - __builtin_popcount(d), __builtin_popcount(d)));
            dp[j] += min(__builtin_popcount(j), k - __builtin_popcount(j));
        }

        ans = min(ans, dp[(1 << k) - 1]);
    }
    cout << ans << "\n";
}
