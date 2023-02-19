//Knuth ??
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 405;
ll ps[N], dp[N][N], v[N];

ll sum(int l, int len){
    return ps[l+len-1] - ps[l-1];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++) ps[i] = ps[i-1] + v[i];
    
    for(int i=2;i<=n;i++){ //for i = 1, dp[i][j] = 0 for all j
        for(int j=1;j<=(n-i+1); j++){
            dp[i][j] = INF_LL;
            for(int k=1;k<i;k++){ //combine arr j, len k with arr j+k, len i-k
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j+k] + sum(j, i));
            }
        }
    }
    cout << dp[n][1];
}
