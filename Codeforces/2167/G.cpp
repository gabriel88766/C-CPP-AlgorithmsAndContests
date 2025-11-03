#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 8005;
ll dp[2][N];
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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        auto aux = v;
        sort(aux.begin(), aux.end());
        aux.resize(unique(aux.begin(), aux.end()) - aux.begin());
        vector<int> idx(n+1);
        for(int i=1;i<=n;i++){
            idx[i] = lower_bound(aux.begin(), aux.end(), v[i]) - aux.begin();
        }
        int sz = aux.size() - 1;
        vector<ll> cst(n+1);
        for(int i=1;i<=n;i++) cin >> cst[i];
        for(int i=0;i<=sz;i++){
            dp[0][i] = dp[1][i] = INF_LL;
        }
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            int b = i & 1;
            for(int j=0;j<=sz;j++){ //just ignore 
                dp[b][j] = dp[b^1][j] + cst[i];
            }
            for(int j=0;j<=idx[i];j++){ //append
                dp[b][idx[i]] = min(dp[b][idx[i]], dp[b^1][j]);
            }


            for(int j=0;j<=sz;j++){
                dp[b^1][j] = INF_LL;
            }
        }
        ll ans = INF_LL;
        for(int j=0;j<=sz;j++){
            ans = min(ans, dp[n & 1][j]);
        }
        cout << ans << "\n";
    }
}
