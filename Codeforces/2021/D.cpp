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
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> dpr(n+1, vector<ll>(m+1, -INF_LL));
        auto dsu = dpr;
        for(int i=1;i<=n;i++){
            vector<ll> v(m+1), ps(m+1);
            for(int j=1;j<=m;j++){
                cin >> v[j];
                ps[j] = v[j] + ps[j-1];
            }
            if(i == 1){
                ll mxps = -INF_LL;
                for(int j=m;j>=1;j--){
                    mxps = max(mxps, ps[j]);
                    dpr[i][j] = mxps - ps[j-1];
                }
                ll mnps = 0;
                for(int j=1;j<=m;j++){
                    dsu[i][j] = ps[j] - mnps;
                    mnps = min(mnps, ps[j]);
                }
            }else{
                ll mxps = -INF_LL, mxsu = -INF_LL;
                ll mxpr = -INF_LL;
                //prefix
                for(int j=m;j>=1;j--){
                    mxsu = max(mxsu, mxps + dsu[i-1][j]);
                    mxps = max(mxps, ps[j]);
                    dpr[i][j] = max(dpr[i][j], mxpr - ps[j-1]);
                    mxpr = max(mxpr, dpr[i-1][j] + mxps);
                    dpr[i][j] = max(dpr[i][j], mxsu - ps[j-1]);
                }
                //for suffix
                ll mnpr = INF_LL;
                mxpr = mxsu = -INF_LL;
                // mxd = -INF_LL, mxp = -INF_LL;
                for(int j=1;j<=m;j++){
                    mxpr = max(mxpr, dpr[i-1][j] - mnpr);
                    mnpr = min(mnpr, ps[j-1]);
                    dsu[i][j] = max(dsu[i][j], mxpr + ps[j]);
                    dsu[i][j] = max(dsu[i][j], ps[j] + mxsu);
                    mxsu = max(mxsu, dsu[i-1][j] - mnpr);
                }
            }
            
        }
        ll ans = -INF_LL;
        for(int j=1;j<=m;j++){
            ans = max(ans, dpr[n][j]);
            ans = max(ans, dsu[n][j]);
        }
        cout << ans << "\n";
    }
}
