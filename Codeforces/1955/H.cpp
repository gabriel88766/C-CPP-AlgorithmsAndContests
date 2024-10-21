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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<char>> gr(n+1, vector<char>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> gr[i][j];
            }
        }
        vector<int> po(k);
        vector<vector<int>> afc(k, vector<int>(11, 0));
        for(int i=0;i<k;i++){
            int x, y;
            cin >> x >> y >> po[i];
            for(int u=1;u<=n;u++){
                for(int v=1;v<=m;v++){
                    if(gr[u][v] == '#'){
                        int dx = abs(x - u);
                        int dy = abs(y - v);
                        int dd = dx*dx + dy*dy;
                        int sqt = sqrt(dd);
                        while(sqt*sqt > dd) sqt--;
                        while((sqt+1)*(sqt+1) <= dd) sqt++;
                        if(sqt*sqt != dd) sqt++;
                        if(sqt <= 10) afc[i][sqt]++;
                    }
                }
            }
            for(int d=1;d<11;d++) afc[i][d] += afc[i][d-1];
        }
        vector<int> p3(11, 1);
        for(int i=1;i<=10;i++) p3[i] = 3 * p3[i-1];
        vector<ll> dp(1<<10, -INF_LL);
        dp[0] = 0;
    
        for(int i=0;i<k;i++){
            vector<ll> ndp(1 << 10, -INF_LL);
            ll mdp = 0;
            for(int j=0;j<(1<<10);j++){
                ndp[j] = max(ndp[j], dp[j] + afc[i][0] * po[i]);
                for(int nb=0;nb<10;nb++){
                    if(j & (1 << nb)){
                        ndp[j] = max(ndp[j], dp[j ^ (1 << nb)] + po[i] * afc[i][nb+1] - p3[nb+1]);
                    }
                }
            }
            
            dp = ndp;
        }
        ll ans = 0;
        for(auto x : dp) ans = max(ans, x);
        cout << ans << "\n";
    }
}
