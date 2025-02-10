#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e3+3;
vector<vector<ll>> dp(2, vector<ll>(N));
ll C[N][N];
ll v[N];
ll ps[N];


void dcdp(int l, int r, int opl, int opr){
    int m = (l+r)/2;
    int opm = opl;
    ll best = INF_LL;
    for(int u = opl; u <= min(opr, m-1); u++){
        if(best > dp[0][u] + C[u+1][m-1]){
            best = dp[0][u] + C[u+1][m-1];
            opm = u;
        }
    }
    dp[1][m] = best;
    if(l == r) return;
    dcdp(l, m, opl, opm);
    dcdp(m+1, r, opm, opr);
}

void solve(int n, int k){
    ll aux = 0;
    for(int i=1;i<=n;i++){
        aux += ps[i-1] - ps[0];
        dp[1][i] = aux;
    }
    for(int i=2;i<=k;i++){
        dp[0] = dp[1];
        dcdp(1, n, i-1, n-1);
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
         cin >> v[i];
         ps[i] = ps[i-1] + v[i];
    }

    for(int i=0;i<=n;i++){
        for(int j=1;j+i<=n;j++){
            C[j][j+i] = ps[j+i] - ps[j-1];
            C[j][j+i] += C[j+1][j+i-1];
        }
    }
    solve(n, k);
    ll ans = INF_LL;
    ll aux = 0;
    for(int i=n;i>=1;i--){
        aux += ps[n] - ps[i];
        ans = min(ans, dp[1][i] + aux);
    }
    cout << ans << "\n";
}
