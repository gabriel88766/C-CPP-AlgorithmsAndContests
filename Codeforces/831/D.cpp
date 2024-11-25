#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
int dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> v(n+1), b(k+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    for(int i=1;i<=k;i++){
        cin >> b[i];
    }
    sort(v.begin() + 1, v.end());
    sort(b.begin() + 1, b.end());
    memset(dp, 127, sizeof(dp));
    dp[0] = 0;
    for(int i=1;i<=k;i++){
        for(int j=n-1;j>=0;j--){
            dp[j+1] = min(dp[j+1], max(dp[j], abs(v[j+1] - b[i]) + abs(b[i] - p)));
        }
        // for(int j=0;j<=n;j++) cout << dp[j] << " ";
        // cout << "\n";
    }
    cout << dp[n] << "\n";
}   
