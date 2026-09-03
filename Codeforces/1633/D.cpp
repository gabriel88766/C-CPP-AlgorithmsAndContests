#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp1[1005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //prep
    memset(dp1, 63, sizeof(dp1));
    dp1[1] = 0;
    for(int i = 1; i<= 1000; i++){
        for(int j=1;j<=i;j++){
            int g = i + i/j;
            if(g <= 1000) dp1[g] = min(dp1[g], dp1[i] + 1); //maximum is 12, then maximum cost is 12 * n;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> b(n), c(n);
        for(int i=0;i<n;i++) cin >> b[i];
        for(int i=0;i<n;i++) cin >> c[i];
        vector<pair<int, int>> cst;
        for(int i=0;i<n;i++){
            cst.push_back({dp1[b[i]], c[i]});
        }
        vector<int> dp(12 * n + 5);
        for(auto [a, b] : cst){
            for(int j = 12 * n; j >= a; j--){
                dp[j] = max(dp[j], dp[j - a] + b);
            }
        }
        cout << dp[min(12 * n, k)] << "\n";
    }
}
