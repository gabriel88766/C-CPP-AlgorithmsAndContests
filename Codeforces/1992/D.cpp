#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        s = "L" + s + "L";
        vector<int> dp(n+2, INF_INT);
        dp[0] = 0;
        for(int i=1;i<=n+1;i++){ 
            if(s[i] == 'C') continue;
            for(int jl = 1; jl <= min(m, i); jl++){
                if(s[i-jl] == 'L') dp[i] = min(dp[i], dp[i-jl]);
            }
            if(s[i-1] == 'W') dp[i] = min(dp[i], dp[i-1] + 1);
        }
        if(dp[n+1] <= k) cout << "YES\n";
        else cout << "NO\n";
    }
}
