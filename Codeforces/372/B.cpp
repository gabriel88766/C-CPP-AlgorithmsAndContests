#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char gr[45][45];
int rr[45][45];
int dp[41][41][41][41];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> gr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            rr[i][j] = rr[i][j-1];
            if(gr[i][j] == '1') rr[i][j] = j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=i;k<=n;k++){
                for(int l=j;l<=m;l++){
                    dp[i][j][k][l] = dp[i][j][k-1][l] + dp[i][j][k][l-1] - dp[i][j][k-1][l-1];
                    int f1 = j-1;
                    for(int cr = k;cr >= i; cr--){
                        f1 = max(f1, rr[cr][l]);
                        dp[i][j][k][l] += l - f1;
                    }
                }
            }
        }
    }
    for(int i=0;i<q;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << dp[a][b][c][d] << "\n";
    }
}
