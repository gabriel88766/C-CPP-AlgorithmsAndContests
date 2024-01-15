#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 505;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(2, vector<int>(k+1, INF_INT));
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        int cur = i & 1;
        int old = (i-1) & 1;
        for(int j=0;j<=k;j++) dp[cur][j] = INF_INT;

        string s;
        cin >> s;
        s = " " + s;
        vector<int> one;
        for(int j=1;j<=m;j++) if(s[j] == '1') one.push_back(j);
        int sz = one.size();
        vector<int> minv(sz+1, INF_INT);
        minv[0] = 0;
        if(sz) minv[1] = 1;
        for(int j=2;j<=sz;j++){
            int minc = INF_INT;
            for(int x=j-1;x<sz;x++){
                minc = min(minc, one[x] - one[x-j+1] + 1);
            }
            minv[j] = minc;
        }
        for(int j=0;j<=k;j++){
            for(int nxt=j;nxt<=k;nxt++){
                if(nxt - j > sz) break;
                dp[cur][nxt] = min(dp[cur][nxt], dp[old][j] + minv[sz-(nxt-j)]);
            }
        }
    }
    int ans = INF_INT;
    for(int i=0;i<=k;i++) ans = min(ans, dp[n&1][i]);
    cout << ans << "\n";
}
