#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
bool dp[N][2];
int a[N], b[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    dp[1][0] = dp[1][1] = true;
    for(int i=2;i<=n;i++){
        if(dp[i-1][0]){
            if(abs(a[i] - a[i-1]) <= k) dp[i][0] = true;
            if(abs(b[i] - a[i-1]) <= k) dp[i][1] = true;
        }
        if(dp[i-1][1]){
            if(abs(a[i] - b[i-1]) <= k) dp[i][0] = true;
            if(abs(b[i] - b[i-1]) <= k) dp[i][1] = true;
        }
    }
    if(dp[n][0] || dp[n][1]) cout << "Yes\n";
    else cout << "No\n";
}
