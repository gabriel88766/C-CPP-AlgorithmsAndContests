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
    ll n, m, x;
    cin >> n >> m >> x;
    vector<ll> c(n);
    vector<vector<ll>> a(n, vector<ll>(m));
    for(int i=0;i<n;i++){
        cin >> c[i];
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    ll ans = INF_LL;
    for(int i=1;i<(1 << n);i++){
        ll cst = 0;
        vector<ll> tt(m);
        for(int j=0;j<n;j++){
            if(i & (1 << j)){
                cst += c[j];
                for(int k=0;k<m;k++){
                    tt[k] += a[j][k];
                }
            }
        }
        bool cok = true;
        for(int k=0;k<m;k++) if(tt[k] < x) cok = false;
        if(cok) ans = min(ans, cst);
    }
    if(ans == INF_LL) cout << "-1\n";
    else cout << ans << "\n";
}
