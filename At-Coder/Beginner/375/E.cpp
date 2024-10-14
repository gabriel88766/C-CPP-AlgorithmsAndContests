#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


ll dp[2][505][505];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m;
    cin >> m;
    int S = 0;
    vector<pair<int,int>> vc[4];
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        S += b;
        for(int j=1;j<=3;j++){
            if(j == a){
                vc[j].push_back({b, 0});
            }else{
                vc[j].push_back({b, 1});
            }
        }
    }
    memset(dp, 63, sizeof(dp));
    if(S % 3) cout << "-1\n";
    else{
        S /= 3;
        dp[1][0][0] = 0;
        for(int i=0;i<m;i++){
            int b = i & 1;
            for(int j=S;j>=0;j--){
                for(int k=S;k>=0;k--){
                    for(int t=1;t<=3;t++){
                        auto [c, w] = vc[t][i];
                        if(t == 1 && j >= c){
                            dp[b][j][k] = min(dp[b][j][k], dp[b^1][j-c][k] + w);
                        }
                        if(t == 2 && k >= c){
                            dp[b][j][k] = min(dp[b][j][k], dp[b^1][j][k-c] + w);
                        }
                        if(t == 3){
                            dp[b][j][k] = min(dp[b][j][k], dp[b^1][j][k] + w);
                        }
                    }
                }
            }
            for(int j=0;j<=S;j++){
                for(int k=0;k<=S;k++){
                    dp[b^1][j][k] = INF_LL;
                }
            }
        }

        int b = (m-1) & 1;
        if(dp[b][S][S] < INF_INT) cout << dp[b][S][S] << "\n";
        else cout << "-1\n";
    }
}
 