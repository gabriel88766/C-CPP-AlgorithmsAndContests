#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[401][401];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, ma, mb;
    cin >> n >> ma >> mb;
    memset(dp, 63, sizeof(dp));
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        for(int j=400;j>=a;j--){
            for(int k=400;k>=b;k--){
                dp[j][k] = min(dp[j][k], dp[j-a][k-b] + c);
            }   
        }
    }
    int lowc = INF_INT;
    for(int i=1;i<=400;i++){
        if(ma*i > 400 || mb*i > 400) break;
        lowc = min(lowc, dp[ma*i][mb*i]);
    }
    if(lowc == INF_INT) cout << "-1\n";
    else cout << lowc << "\n";
}
