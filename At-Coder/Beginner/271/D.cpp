#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

pair<int, int> dp[101][10001];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, S;
    cin >> n >> S;
    pair<int, int> nullp = {-1, -1};
    for(int i=0;i<=n;i++) for(int j=0;j<=S;j++) dp[i][j] = nullp;
    dp[0][0] = {1, 1}; //means ok
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        for(int j=0;j<=S;j++){
            if(j >= a && dp[i-1][j-a] != nullp){
                dp[i][j] = {j-a, 0};
            }
            if(j >= b && dp[i-1][j-b] != nullp){
                dp[i][j] = {j-b, 1};
            }
        }
    }
    if(dp[n][S] != nullp){
        cout << "Yes\n";
        string ans;
        int cur = S;
        for(int i=n;i>=1;i--){
            if(dp[i][cur].second == 0) ans += 'H';
            else ans += 'T';
            cur = dp[i][cur].first;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }else cout << "No\n";
}
