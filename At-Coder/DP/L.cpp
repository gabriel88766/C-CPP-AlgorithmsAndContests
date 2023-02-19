#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
ll dp[N][N][2], v[N]; //0 for first player, 1 for second player

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){ //init.
        for(int j=1;j<=(n-i+1);j++){
            pair<ll,ll> p = max(make_pair(v[j] + dp[i-1][j+1][1], dp[i-1][j+1][0]), make_pair(v[j+i-1] + dp[i-1][j][1], dp[i-1][j][0]));
            dp[i][j][0] = p.first;
            dp[i][j][1] = p.second; 
        }
    }
    cout << dp[n][1][0] - dp[n][1][1];
}
