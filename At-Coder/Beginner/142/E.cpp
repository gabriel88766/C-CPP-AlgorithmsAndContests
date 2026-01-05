#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[1 << 12];
const int N = 1005;
int a[N];
int msk[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dp, 63, sizeof(dp));
    int n, m;
    cin >> n >> m;
    int g = (1 << n) - 1;
    dp[0] = 0;
    for(int i=1;i<=m;i++){
        cin >> a[i];
        int qnt;
        cin >> qnt;
        int cm = 0;
        for(int j=0;j<qnt;j++){
            int x;
            cin >> x;
            cm |= (1 << (x-1));
        }
        msk[i] = cm;
    }
    for(int i=0;i<(1<<n);i++){
        if(dp[i] == INF_INT) continue;
        for(int j=1;j<=m;j++){
            dp[i | msk[j]] = min(dp[i | msk[j]], dp[i] + a[j]);
        }
    }
    if(dp[g] == INF_INT) cout << "-1\n";
    else cout << dp[g] << "\n";
}
