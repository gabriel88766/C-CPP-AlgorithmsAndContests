#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[11][17][17];
tuple<int, int, int> par[11][17][17];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> h(n+1);
    for(int i=1;i<=n;i++){
        cin >> h[i];
        h[i] += 1;
    }
    memset(dp, 63, sizeof(dp));
    dp[1][h[1]][h[2]] = 0;
    for(int i=2;i<=n-1;i++){
        for(int j=0; j <= 16; j++){
            for(int k=0;k<=16;k++){
                if(dp[i-1][j][k] != INF_INT){
                    for(int x = 0; x <= 16; x++){
                        int v1 = max(0, j - b * x);
                        int v2 = max(0, k - a * x);
                        int v3 = max(0, h[i+1] - b * x);
                        if(v1 != 0) continue;
                        if(dp[i][v2][v3] > dp[i-1][j][k] + x){
                            dp[i][v2][v3] = dp[i-1][j][k] + x;
                            par[i][v2][v3] = {j, k, x};
                        }
                    }
                }
            }
        }
    }
    cout << dp[n-1][0][0] << "\n";
    int cj = 0, ck = 0;
    for(int i=n-1;i>=2;i--){
        auto [nj, nk, x] = par[i][cj][ck];
        for(int j=0;j<x;j++) cout << i << " ";
        cj = nj;
        ck = nk;
    }
    cout << "\n";
}
