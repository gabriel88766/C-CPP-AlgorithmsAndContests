#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 200005;
int adj0[N], adj1[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> v(n+1);
        vector<int> num(n+1);
        for(int i=1;i<=n;i++){
            cin >> num[i];
            v[num[i]].push_back(i);
        }
        vector<vector<int>> dp(2, vector<int>(n+1, INF_INT));
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            auto it = lower_bound(v[num[i]].begin(), v[num[i]].end(), i);
            dp[0][i] = min(dp[0][i-1], dp[1][i-1]) + 1;
            if(it != v[num[i]].begin()){
                --it;
                dp[1][i] = min(dp[0][*it] - 1, dp[1][*it]);
            }
        }
        cout << n - min(dp[0][n], dp[1][n]) << "\n";
    }
}
