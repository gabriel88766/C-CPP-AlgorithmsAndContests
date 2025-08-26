#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
int dp1[N][N], dp2[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int x;
                cin >> x;
                if(i == 1 && j == 1){
                    dp1[i][j] = dp2[i][j] = x;
                }else{
                    dp1[i][j] = INF_INT; //mn
                    dp2[i][j] = -INF_INT; //mx
                    if(i != 1){
                        dp1[i][j] = min(dp1[i][j], dp1[i-1][j] + x);
                        dp2[i][j] = max(dp2[i][j], dp2[i-1][j] + x);
                    }
                    if(j != 1){
                        dp1[i][j] = min(dp1[i][j], dp1[i][j-1] + x);
                        dp2[i][j] = max(dp2[i][j], dp2[i][j-1] + x);
                    }
                }
            }
        }
        if(dp1[n][m] <= 0 && dp2[n][m] >= 0  && (dp1[n][m] % 2 == 0)) cout << "YES\n";
        else cout << "NO\n";
    }
}
