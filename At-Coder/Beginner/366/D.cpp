#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
const int N = 105;
ll A[N][N][N];
ll ps[N][N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                cin >> A[i][j][k];
            }
        }
    }
    int q;
    cin >> q;
    //preprocess
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                ps[i][j][k] = ps[i-1][j][k] + ps[i][j-1][k] + ps[i][j][k-1] - ps[i-1][j-1][k] - \
                    ps[i-1][j][k-1] - ps[i][j-1][k-1] + ps[i-1][j-1][k-1];
                ps[i][j][k] += A[i][j][k];
            }
        }
    }
    //queries
    for(int i=0;i<q;i++){
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        ll ans = ps[x2][y2][z2] - ps[x1-1][y2][z2] - ps[x2][y1-1][z2] - ps[x2][y2][z1-1] + ps[x1-1][y1-1][z2] + \
            ps[x1-1][y2][z1-1] + ps[x2][y1-1][z1-1] - ps[x1-1][y1-1][z1-1];
        cout << ans << "\n";
    }
}
