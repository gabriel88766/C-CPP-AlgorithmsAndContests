#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int gr[31][31];
ll dp[31][31][61][61];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll h, w, k;
    cin >> h >> w >> k;
    map<ll, ll> mp;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
            mp[gr[i][j]]++;
        }
    }
    ll ans = INF_LL;
    for(auto [val, qt] : mp){
        ll cm = min(qt, h + w - 1);
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                for(int u=0;u<=k;u++){
                    for(int v=0;v<=cm;v++){
                        dp[i][j][u][v] = INF_LL;
                    }
                }
            }
        }
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                int du = gr[i][j] > val ? 1 : 0;
                int dv = gr[i][j] == val ? 1 : 0;
                ll s = gr[i][j] > val ? gr[i][j] : 0;
                if(i == 1 && j == 1){
                    dp[i][j][du][dv] = s;
                    continue;
                }
                for(int u=du;u<=k;u++){
                    for(int v=dv;v<=cm;v++){
                        if(i != 1){
                            dp[i][j][u][v] = min(dp[i][j][u][v], dp[i-1][j][u-du][v-dv] + s);
                        }
                        if(j != 1){
                            dp[i][j][u][v] = min(dp[i][j][u][v], dp[i][j-1][u-du][v-dv] + s);
                        }
                    }
                }
            }
        }
        for(int u=0;u<=k;u++){
            for(int v = k-u; v <= cm; v++){
                if(dp[h][w][u][v] != INF_LL){
                    ll cur = dp[h][w][u][v];
                    cur += (k - u) * val;
                    ans = min(ans, cur);
                }
            }
        }
    }
    cout << ans << "\n";
}
