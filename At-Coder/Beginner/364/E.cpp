#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[81][10001];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, x, y;
    cin >> n >> x >> y;
    vector<pair<ll, ll>> vp(n);
    for(int i=0;i<n;i++) cin >> vp[i].first >> vp[i].second;
    memset(dp, 63, sizeof(dp));
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int qt=i+1;qt>=1;qt--){
            for(int w=x;w>=vp[i].first;w--){
                dp[qt][w] = min(dp[qt][w], dp[qt-1][w-vp[i].first] + vp[i].second);       
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(dp[i][j] <= y) ans = i;
        }
    }
    if(ans != n) cout << ans+1 << "\n";
    else cout << ans << "\n";
}

