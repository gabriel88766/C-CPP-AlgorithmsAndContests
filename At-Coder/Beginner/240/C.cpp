#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool dp[2][10005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, x;
    cin >> n >> x;
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        int b = i % 2;
        for(int j=0;j<=x;j++) dp[b][j] = false;
        int u, v;
        cin >> u >> v;
        for(int j=u;j<=x;j++) if(dp[b^1][j-u]) dp[b][j] = 1;
        for(int j=v;j<=x;j++) if(dp[b^1][j-v]) dp[b][j] = 1;
    }
    int b = n % 2;
    if(dp[b][x]) cout << "Yes\n";
    else cout << "No\n";

}
