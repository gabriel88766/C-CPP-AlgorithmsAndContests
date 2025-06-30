#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2002;
int dp[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    vector<string> gr(h);
    for(int i=0;i<h;i++) cin >> gr[i];
    memset(dp, 63, sizeof(dp));
    dp[h-1][w-1] = 0;
    for(int i=h-1;i>=0;i--){
        for(int j=w-1;j>=0;j--){
            if(i == h-1 && j == w-1) continue;
            if(i == h-1) dp[i][j] = -dp[i][j+1] + (gr[i][j+1] == '+' ? 1 : -1);
            else if(j == w-1) dp[i][j] = -dp[i+1][j] + (gr[i+1][j] == '+' ? 1 : -1);
            else dp[i][j] = -min(dp[i+1][j] - (gr[i+1][j] == '+' ? 1 : -1), dp[i][j+1] - (gr[i][j+1] == '+' ? 1 : -1));
        }
    }
    if(dp[0][0] > 0) cout << "Takahashi\n";
    else if(dp[0][0] == 0) cout << "Draw\n";
    else cout << "Aoki\n";
}
