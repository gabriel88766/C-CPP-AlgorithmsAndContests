#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
char gr[N][N];
int dp1[N][N], dp2[N][N], dp3[N][N];
ll ans[26];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> gr[i][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=n;j>=1;j--){
            if(gr[i][j] == gr[i+1][j]) dp1[i][j] = dp1[i+1][j] + 1;
            else dp1[i][j] = 1;
            if(gr[i][j] == gr[i][j+1]) dp2[i][j] = dp2[i][j+1] + 1;
            else dp2[i][j] = 1;
            if(gr[i][j] == gr[i+1][j+1]){
                dp3[i][j] = min({dp3[i+1][j+1] + 1, dp2[i][j], dp1[i][j]});
            }else dp3[i][j] = 1;
            ans[gr[i][j] - 'A'] += dp3[i][j];
        }
    }
    for(int i=0;i<k;i++) cout << ans[i] << "\n";
}
