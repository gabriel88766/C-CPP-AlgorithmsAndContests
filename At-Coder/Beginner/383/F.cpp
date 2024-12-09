#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 505;
vector<pair<ll,ll>> cl[N];
ll dp2[50005], dp[50005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, x, k;
    cin >> n >> x >> k;
    for(int i=1;i<=n;i++){
        ll p, u, c;
        cin >> p >> u >> c;
        cl[c].push_back({p, u});
    }
    for(int i=1;i<=n;i++){
        if(cl[i].size()){
            for(int j=0;j<=x;j++) dp2[j] = -INF_LL;
            for(auto [a, b] : cl[i]){ // O(N*X)
                for(int j=x;j>=a;j--){
                    dp2[j] = max(dp2[j], dp[j-a] + b + k);
                    dp2[j] = max(dp2[j], dp2[j-a] + b);
                }
            }
            for(int j=0;j<=x;j++) dp[j] = max(dp2[j], dp[j]);
        }
    }
    cout << dp[x] << "\n";
}
 