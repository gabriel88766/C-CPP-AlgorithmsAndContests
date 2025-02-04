#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e6;
int dp[N][2][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m;
    cin >> m;
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] == '1') dp[i][0][0] = 1;
        else dp[i][0][1] = 1;
    }
    int gap = 1;
    for(int i=1;i<=m;i++){
        int b = i & 1;
        int igap = gap;
        gap *= 3;
        for(int j=0;j<n;j += gap){
            dp[j][b][0] = dp[j][b][1] = INF_INT;
            for(int x = 0; x < 9; x++){
                int cnt = 0, dps = 0;
                for(int y=0;y<3;y++){
                    if(x & (1 << y)){
                        cnt++;
                        dps += dp[j + y*igap][b^1][1];
                    }else{
                        dps += dp[j + y*igap][b^1][0];
                    }
                }
                if(cnt >= 2) dp[j][b][1] = min(dp[j][b][1], dps);
                else dp[j][b][0] = min(dp[j][b][0], dps);
            }
        }
    }
    cout << max(dp[0][m&1][0], dp[0][m&1][1]) << "\n";
}
