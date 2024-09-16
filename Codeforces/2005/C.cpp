#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char let[] = {'n', 'a', 'r', 'e', 'k'};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> dp(n+1, vector<int>(5, -INF_INT));
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=1;i<=n;i++){
            string s;
            cin >> s;
            for(int src=0;src<5;src++){
                dp[i][src] = max(dp[i][src], dp[i-1][src]);
                int cnt = 0;
                int dst = src;
                for(int j=0;j<m;j++){
                    if(s[j] == let[dst]) cnt++, dst++;
                    else{
                        for(int k=0;k<5;k++) if(let[k] == s[j]) cnt--;
                    }
                    dst %= 5;
                }
                dp[i][dst] = max(dp[i][dst], dp[i-1][src] + cnt);
            }
        }
        int ans = 0;
        for(int j=0;j<5;j++) ans = max(ans, dp[n][j]-2*j);
        cout << ans << "\n";
    }
}
