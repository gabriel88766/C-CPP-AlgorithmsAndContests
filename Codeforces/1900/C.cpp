#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N =  3e5+3;
int l[N], r[N], dp[N];
char v[N];
//cout << fixed << setprecision(6)
void dfs(int u){
    if(!l[u] && !r[u]){
        dp[u] = 0;
        return;
    }
    if(l[u]){
        dfs(l[u]);
    }
    if(r[u]){
        dfs(r[u]);
    }
    if(v[u] == 'L') dp[u] = min(dp[l[u]], dp[r[u]] + 1);
    else if(v[u] == 'R') dp[u] = min(dp[l[u]] + 1, dp[r[u]]);
    else dp[u] = min(dp[l[u]] + 1, dp[r[u]] + 1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    memset(dp, 63, sizeof(dp));
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=1;i<=n;i++){
            cin >> l[i] >> r[i];
        }
        dfs(1);
        cout << dp[1] << "\n";
        for(int i=1;i<=n;i++){
            v[i] = l[i] = r[i] = 0;
            dp[i] = INF_INT;
        }
    }
}
 