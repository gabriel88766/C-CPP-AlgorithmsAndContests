#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
ll dp[N][4];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    dp[0][1] = dp[0][2] = dp[0][3] = INF_LL;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(s[i] == 'h'){
            dp[i][0] = dp[i-1][0] + x;
            dp[i][1] = min(dp[i-1][1], dp[i-1][0]);
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3];
        }else if(s[i] == 'a'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1] + x;
            dp[i][2] = min(dp[i-1][2], dp[i-1][1]);
            dp[i][3] = dp[i-1][3];
        }else if(s[i] == 'r'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2] + x;
            dp[i][3] = min(dp[i-1][3], dp[i-1][2]);
        }else if(s[i] == 'd'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3] + x;
        }else{
            for(int j=0;j<=3;j++) dp[i][j] = dp[i-1][j];
        }
    }
    cout << min(dp[n][0], min(dp[n][1], min(dp[n][2], dp[n][3]))) << "\n";
}
