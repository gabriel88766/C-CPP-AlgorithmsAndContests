#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[3][200005];

vector<vector<int>> ot = {{1, 2}, {0, 2}, {0, 1}};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    for(int i=1;i<=n;i++){ // S beats P, R beats S, P beats R;; S, P, R
        int al1, al2;
        int na;
        if(s[i] == 'S'){
            al1 = 2, al2 = 0;
            na = 1;
        }else if(s[i] == 'P'){
            al1 = 0, al2 = 1;
            na = 2;
        }else if(s[i] == 'R'){
            al1 = 1, al2 = 2;
            na = 0;
        }else assert(1 == 0);
        dp[na][i] = -INF_INT;
        dp[al1][i] = max(dp[ot[al1][0]][i-1] + 1, dp[ot[al1][1]][i-1] + 1);
        dp[al2][i] = max(dp[ot[al2][0]][i-1], dp[ot[al2][1]][i-1]);
    }   
    int ans = max(dp[0][n], dp[1][n]);
    ans = max(ans, dp[2][n]);
    cout << ans << "\n";
}
