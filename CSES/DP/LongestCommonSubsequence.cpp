#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[1005][1005];
int a[1005], b[1005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int j=1;j<=m;j++) cin >> b[j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + (a[i] == b[j] ? 1 : 0)});
        }
    }
    cout << dp[n][m] << "\n";
    vector<int> ans;
    int x = n, y = m;
    while(dp[x][y]){
        while(dp[x][y] == dp[x-1][y]) x--;
        while(dp[x][y] == dp[x][y-1]) y--;
        ans.push_back(a[x]);
        x--, y--;
    }
    reverse(ans.begin(), ans.end());
    for(auto &x : ans) cout << x << " ";
    cout << "\n";
}
