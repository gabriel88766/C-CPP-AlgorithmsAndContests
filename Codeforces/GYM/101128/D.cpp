#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[41];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m, maxsum = 0;
    cin >> n >> m;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i+j]++;
        }
    }
    for(int i=1;i<=40;i++) maxsum = max(maxsum, dp[i]);
    for(int i=1;i<=40;i++) if(dp[i] == maxsum) ans.push_back(i);
    for(auto u : ans) cout << u << "\n";
}
