#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005, M = 50005;
ll p[N], v[N];
ll dp[N][M];
ll dp2[M];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> p[i] >> v[i];
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            if(j >= p[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-p[i]] + v[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    ll mx = dp[n][m];
    string ans(n, '0');
    for(int i = n; i >= 1; i--){
        ll mv1 = 0;
        for(int j=0;j<=m;j++) mv1 = max(mv1, dp2[j] + dp[i-1][m-j]);
        ll mv2 = 0;
        for(int j=0;j<=m-p[i];j++) mv2 = max(mv2, v[i] + dp2[j] + dp[i-1][m-p[i]-j]);
        if(mv1 == mx && mv2 == mx){
            ans[i-1] = 'B';
        }else if(mv1 == mx && mv2 != mx){
            ans[i-1] = 'C';
        }else if(mv1 != mx && mv2 == mx){
            ans[i-1] = 'A';
        }
        for(int j=m;j>=p[i];j--) dp2[j] = max(dp2[j], dp2[j-p[i]] + v[i]);
    }
    cout << ans << "\n";
}
