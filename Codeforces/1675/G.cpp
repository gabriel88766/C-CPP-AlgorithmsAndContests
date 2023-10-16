#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[252][252][502];
int mid = 251;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    memset(dp, 63, sizeof(dp));
    for(int x = 0;x<=m;x++){
        int dif = v[1] - x;
        dp[1][x][mid+dif] = abs(dif);
    }
    for(int i=2;i<=n;i++){
        for(int x = 0;x<=m/i;x++){
            for(int j=-m;j<=m;j++){
                for(int k=x;k<=m/(i-1);k++){
                    int lst = j - v[i] + x;
                    if(abs(lst) > m) continue;
                    dp[i][x][mid+j] = min(dp[i][x][mid+j], dp[i-1][k][mid+lst] + abs(j));
                }
            }
        }
    }
    int ans = INF_INT;
    for(int i=0;i<=m;i++) ans = min(ans, dp[n][i][mid]);
    cout << ans << "\n";
}
