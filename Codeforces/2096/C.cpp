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
        vector<vector<ll>> gr(n+1, vector<ll>(n+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> gr[i][j];
            }
        }
        vector<ll> a(n+1), b(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        ll cst = 0;
        vector<ll> dp(2);
        dp[1] = a[1];
        for(int i=2;i<=n;i++){
            vector<ll> ndp(2, INF_LL);
            for(int k=0;k<2;k++){
                for(int nk=0;nk<2;nk++){
                    bool ok = true;
                    for(int j=1;j<=n;j++){
                        if(gr[i-1][j] + k == gr[i][j] + nk) ok = false;
                    }
                    if(ok){
                        ndp[nk] = min(ndp[nk], dp[k] + a[i] * nk);
                    }
                }
            }
            dp = ndp;
        }
        cst = min({INF_LL, dp[0], dp[1]});
        dp[0] = 0;
        dp[1] = b[1];
        for(int j=2;j<=n;j++){
            vector<ll> ndp(2, INF_LL);
            for(int k=0;k<2;k++){
                for(int nk=0;nk<2;nk++){
                    bool ok = true;
                    for(int i=1;i<=n;i++){
                        if(gr[i][j-1] + k == gr[i][j] + nk) ok = false;
                    }
                    if(ok){
                        ndp[nk] = min(ndp[nk], dp[k] + b[j] * nk);
                    }
                }
            }
            dp = ndp;
        }
        cst = min({INF_LL, cst + dp[0], cst + dp[1]});
        if(cst == INF_LL) cout << "-1\n";
        else cout << cst << "\n";
    }
}
