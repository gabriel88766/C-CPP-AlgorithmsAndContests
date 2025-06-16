#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
int dp[2][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dp, 0xFF, sizeof(dp));
    int n, h, m;
    cin >> n >> h >> m;
    dp[0][h] = m;
    int ans = 0;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        int bt = i & 1;
        for(int j=0;j<=h;j++) dp[bt][j] = -1; //impossible state
        for(int j=0;j<=h;j++){
            if(dp[bt^1][j] != -1){
                if(j >= a) dp[bt][j-a] = max(dp[bt][j-a], dp[bt^1][j]);
                if(dp[bt^1][j] >= b) dp[bt][j] = max(dp[bt][j], dp[bt^1][j] - b);
            }
        }
        bool ok = false;
        for(int j=0;j<=h;j++) if(dp[bt][j] != -1) ok = true;
        if(ok) ans++;
    }
    cout << ans << "\n";
}
