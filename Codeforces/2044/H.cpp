#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
ll gr[N][N];
ll ps1[N][N];
ll ps2[N][N];
ll ps3[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> gr[i][j];
                ps1[i][j] = ps1[i][j-1] + ps1[i-1][j] - ps1[i-1][j-1];
                ps1[i][j] += gr[i][j];
                ps2[i][j] = ps2[i][j-1] + ps2[i-1][j] - ps2[i-1][j-1];
                ps2[i][j] += gr[i][j] * j;
                ps3[i][j] = ps3[i][j-1] + ps3[i-1][j] - ps3[i-1][j-1];
                ps3[i][j] += gr[i][j] * i;
            }
        } 
        for(int i=1;i<=q;i++){
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            ll ans = ps2[x2][y2] - ps2[x1-1][y2] - ps2[x2][y1-1] + ps2[x1-1][y1-1];
            ans -= (y1-1) * (ps1[x2][y2] - ps1[x1-1][y2] - ps1[x2][y1-1] + ps1[x1-1][y1-1]);
            // cout << ans << " ";
            ll aux = ps3[x2][y2] - ps3[x1][y2] - ps3[x2][y1-1] + ps3[x1][y1-1];
            aux -= x1 * (ps1[x2][y2] - ps1[x1][y2] - ps1[x2][y1-1] + ps1[x1][y1-1]);
            ans += (y2 - y1 + 1) * aux;
            cout << ans << " ";
        }
        cout << "\n";
    }
}
