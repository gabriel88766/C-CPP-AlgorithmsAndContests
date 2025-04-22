#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

double dp[5001][256];
ll s[9], c[9];
double p[9];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, x;
    cin >> n >> x;
    for(int i=0;i<n;i++) cin >> s[i] >> c[i] >> p[i];
    for(int i=0;i<n;i++) p[i] /= 100;
    for(int i=1;i<=x;i++){
        for(int j=0;j<(1 << n);j++){
            for(int k=0;k<n;k++){
                if(i < c[k]) continue;
                if(j & (1 << k)){
                    dp[i][j] = max(dp[i][j], p[k] * (dp[i-c[k]][j ^ (1 << k)] + s[k]) + (1 - p[k]) * dp[i-c[k]][j]);
                }
            }
        }
    }
    cout <<fixed << setprecision(10) << dp[x][(1 << n)-1] << "\n";
}
