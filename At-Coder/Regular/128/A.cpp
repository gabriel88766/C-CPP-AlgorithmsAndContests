#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
double dp[2][N];
int par[2][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        //normalize
        dp[0][i-1] /= max(dp[0][i-1], dp[1][i-1]);
        dp[1][i-1] /= max(dp[0][i-1], dp[1][i-1]);
        int x;
        cin >> x;
        if(dp[1][i-1] / x > dp[0][i-1]){
            dp[0][i] = dp[1][i-1] / x;
            par[0][i] = 1;
        }else{
            dp[0][i] = dp[0][i-1];
            par[0][i] = 0;
        }
        if(dp[0][i-1] * x > dp[1][i-1]){
            dp[1][i] = dp[0][i-1] * x;
            par[1][i] = 1;
        }else{
            dp[1][i] = dp[1][i-1];
            par[1][i] = 0;
        }
    }
    vector<int> ans;
    int c = 0;
    for(int i=n;i>=1;i--){
        ans.push_back(par[c][i]);
        c ^= par[c][i];
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}
