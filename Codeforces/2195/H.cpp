#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

tuple<int, int, int> par[500][250][500];
int ans[500][250][500];
int bst[500];
tuple<int, int, int> bstp[500];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        //starts at 0 0 0
        for(int i=0;i<=3*n;i++){
            for(int j=0;j<=3*n;j++){
                if(i != 0 || j != 0) ans[0][i][j] = -INF_INT;
            }
        }
        for(int i=1;i<=3*n;i++){
            //prepare from last step
            for(int j = 0; j <= 3*n; j++){
                if(j == 0){
                    bst[0] = ans[i-1][0][0];
                    bstp[0] = {i-1, 0, 0};
                    continue;
                }else{
                    bst[j] = bst[j-1];
                    bstp[j] = bstp[j-1];
                }
                for(int b = 0; 2*b <= j; b++){
                    int a = j - 2 * b;
                    if(2*a + b > 3 * n) continue;
                    if(ans[i-1][a][b] + a + b > bst[j]){
                        bst[j] = ans[i-1][a][b] + a + b;
                        bstp[j] = {i-1, a, b};
                    }
                }
            }
            //do current step
            for(int a = 0; 2 * a <= 3 * n; a++){
                for(int b = 0; 2*a + b <= 3 * n; b++){
                    int mx_cl = 3 * n - 2 * a - b;
                    ans[i][a][b] = bst[mx_cl];
                    par[i][a][b] = bstp[mx_cl];
                }
            }
        }
        //Proved by AC!
        cout << ans[3*n][0][0] << "\n";
        int cur = 3*n, ca = 0, cb = 0;
        vector<int> cp(3*n+1, 1);
        while(cur != 0){
            auto [ncur, na, nb] = par[cur][ca][cb];
            for(int i=0;i<na;i++){
                cout << ncur << " " << cp[ncur]++ << " ";
                cout << ncur << " " << cp[ncur]++ << " ";
                cout << cur << " " << cp[cur]++ << "\n";
            }
            for(int i=0;i<nb;i++){
                cout << ncur << " " << cp[ncur]++ << " ";
                cout << cur << " " << cp[cur]++ << " ";
                cout << cur << " " << cp[cur]++ << "\n";
            }




            cur = ncur;
            ca = na;
            cb = nb;
        }

    }
}
