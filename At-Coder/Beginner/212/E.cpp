#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
ll dp[N][N];
vector<int> forb[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        forb[a].push_back(b);
        forb[b].push_back(a);
    }
    dp[0][1] = 1;
    for(int i=1;i<=k;i++){
        ll cursum = 0;
        for(int j=1;j<=n;j++) cursum = (cursum + dp[i-1][j]) % MOD;
        for(int j=1;j<=n;j++){
            dp[i][j] = cursum;
            for(auto v : forb[j]){
                dp[i][j] = (MOD + dp[i][j] - dp[i-1][v]) % MOD;
            }
            dp[i][j] = (dp[i][j] + MOD - dp[i-1][j]) % MOD;
        }
    }
    cout << dp[k][1];
}
