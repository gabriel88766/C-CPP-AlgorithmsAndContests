#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char gr[105][105];
char ans[105][105];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> gr[i][j];
            ans[i][j] = gr[i][j];
        }
    }
    for(int j=2;j<=n;j++) ans[1][j] = gr[1][j-1];
    for(int i=2;i<=n;i++) ans[i][n] = gr[i-1][n];
    for(int j=n-1;j>=1;j--) ans[n][j] = gr[n][j+1];
    for(int i=n-1;i>=1;i--) ans[i][1] = gr[i+1][1];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
