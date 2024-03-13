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
        int n, m, x;
        cin >> n >> m >> x;
        vector<vector<bool>> dp(2, vector<bool>(n+1, false));
        vector<bool> rst(n+1, false);
        dp[0][x] = true;
        for(int i=1;i<=m;i++){
            int jmp;
            char c;
            cin >> jmp >> c;
            dp[i&1] = rst;
            for(int j=1;j<=n;j++){
                if(dp[(i&1)^1][j]){
                    if(c == '0'){
                        int g1 = j + jmp;
                        if(g1 > n) g1 -= n;
                        dp[i&1][g1] = true;
                    }else if(c == '1'){
                        int g1 = j - jmp;
                        if(g1 <= 0) g1 += n;
                        dp[i&1][g1] = true;
                    }else{
                        int g1 = j - jmp;
                        if(g1 <= 0) g1 += n;
                        dp[i&1][g1] = true;
                        int g2 = j + jmp;
                        if(g2 > n) g2 -= n;
                        dp[i&1][g2] = true;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(dp[m&1][i]) ans.push_back(i);
        }
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
