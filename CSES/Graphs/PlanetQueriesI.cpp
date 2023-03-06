#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 30;
int dp[N][M];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> dp[i][0];
    for(int i=1;i<30;i++){
        for(int j=1;j<=n;j++){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
    for(int i=1;i<=q;i++){
        int a,b;
        cin >> a >> b;
        int cur = a;
        for(int j=M-1;j>=0;j--){
            if(b & (1 << j)) cur = dp[cur][j];
        }
        cout << cur << '\n';
    }
}
 