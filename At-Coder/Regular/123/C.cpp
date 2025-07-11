#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool dp[20][60][21]; //cur number, numbers available (up to 60), carry (up to 20)
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        //K is small.
        //we need to check if K is ok using dp.
        int n = s.size();
        int l = 1, h = 60;
        while(l != h){
            int m = l + (h - l)/2;
            memset(dp, 0, sizeof(dp));
            dp[n][m][0] = true;
            for(int i=n;i>=1;i--){
                for(int j=m;j>=1;j--){
                    for(int k=20;k>=0;k--){
                        if(!dp[i][j][k]) continue;
                        int mn = k + j;
                        int mx = k + 3*j;
                        int bg = s[i-1] - '0';
                        for(int x = bg; x <= mx; x += 10){
                            int c = x / 10;
                            assert(c <= 20);
                            if(x < mn){
                                //then we need to reduce
                                if(x >= k){
                                    //then we can reduce
                                    dp[i-1][x-k][c] = true;
                                }
                                continue;
                            } 
                            
                            dp[i-1][j][c] = true;
                        }
                    }
                }
            }
            bool ok = false;
            for(int j=0;j<=m;j++) if(dp[0][j][0]) ok = true;
            if(ok) h = m;
            else l = m + 1;
        }
        cout << l << "\n";
    }
}
