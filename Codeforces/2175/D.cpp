#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[370][370], ndp[370][370];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> vp;
        vp.push_back({0, 0});
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            if(x > vp.back().first){
                vp.push_back({x, i});
            }
        }
        for(int i=1;i<vp.size();i++){
            auto [vc, pos] = vp[i];
            auto [vo, xxx] = vp[i-1];
            for(int val = vo+1;val<=vc;val++){
                for(int j=val;j<=k;j++){
                    for(int u=0;u<val;u++){
                        dp[j - val][val] = max(dp[j - val][val], dp[j][u] + (val - u) * (n+1-pos));
                    }
                }
            }
        }
        ll ans = 0;
        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                ans = max(ans, dp[i][j]);
                dp[i][j] = 0;
            }
        }
        cout << ans << "\n";
    }
}
