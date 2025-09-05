#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<vector<double>> dp(2, vector<double>(N));
double ps1[N], ps2[N], ps3[N];

double C(int l, int r){
    return ps2[r] - ps2[l-1] - ps1[l-1] * (ps3[r] - ps3[l-1]);
}

void dcdp(int l, int r, int opl, int opr){
    if(l > r) return;
    int m = (l+r)/2;
    int opm = opl;
    double best = 1e100; //minimize or maximize?
    for(int u = opl; u <= min(opr, m-1); u++){
        if(best > dp[0][u] + C(u+1, m)){
            best = dp[0][u] + C(u+1, m);
            opm = u;
        }
    }
    dp[1][m] = best;
    dcdp(l, m-1, opl, opm);
    dcdp(m+1, r, opm, opr);
}

void solve(int n, int k){
    for(int i=1;i<=n;i++){
        dp[1][i] = C(1, i);
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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++){
         cin >> v[i];
         ps1[i] = ps1[i-1] + v[i]; //the sum
         ps2[i] = ps2[i-1] + ps1[i] / v[i]; //for same array
         ps3[i] = ps3[i-1] + 1.0 / v[i]; // auxiliary
    }
    solve(n, k);
    cout << fixed << setprecision(15) << dp[1][n] << "\n";

}
