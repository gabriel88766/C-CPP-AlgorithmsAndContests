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
    int n;
    cin >> n;
    ll dp[10], ndp[10];
    memset(dp, 192, sizeof(dp));
    dp[0] = 0;

    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        vector<ll> v[4];
        for(int j=0;j<k;j++){
            int c;
            ll dmg;
            cin >> c >> dmg;
            v[c].push_back(dmg);
        }
        for(int j=1;j<=3;j++) sort(v[j].begin(), v[j].end(), greater<ll>());
        ll b[4], d[4];
        b[1] = b[2] = b[3] = -INF_LL; //{{1}, {2}, {3}} , {{1,1}, {1,2}}, {1,1,1}}
        d[1] = d[2] = d[3] = -INF_LL;
        for(int j=1;j<=3;j++) if(v[j].size()) {b[1] = max(b[1], v[j][0]); d[1] = max(d[1], 2*v[j][0]);}
        if(v[1].size() >= 2){
            b[2] = max(b[2], v[1][0] + v[1][1]);
            d[2] = max(d[2], 2*v[1][0] + v[1][1]);
        }
        if(v[1].size() && v[2].size()){
            b[2] = max(b[2], v[1][0] + v[2][0]);
            d[2] = max(d[2], 2*v[1][0] + v[2][0]);
            d[2] = max(d[2], v[1][0] + 2*v[2][0]);
        }
        if(v[1].size() >= 3){
            b[3] = v[1][0] + v[1][1] + v[1][2];
            d[3] = max(d[3], 2*v[1][0] + v[1][1] + v[1][2]);
        }
        for(int j=0;j<=9;j++) ndp[j] = dp[j];
        for(int j=0;j<=9;j++){
            for(int x = 1; x <=3; x++){
                if(b[x] < 0) continue;
                int old = (j - x + 10) % 10;
                if(dp[old] >= 0){
                    if(old > j) ndp[j] = max(ndp[j], dp[old] + d[x]);
                    else ndp[j] = max(ndp[j], dp[old] + b[x]);
                }
            }
        }
        for(int j=0;j<=9;j++) dp[j] = ndp[j];
    }
    ll ans = 0;
    for(int i=0;i<=9;i++) ans = max(ans, dp[i]);
    cout << ans;
}
