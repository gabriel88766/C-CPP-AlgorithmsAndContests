#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<bool> can(n+1, true);
        vector<vector<char>> vx(n+1, vector<char>(k+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                cin >> vx[i][j];
            }
        }
        for(int j=1;j<=k;j++){
            for(int i=2;i<=n;i++){
                if(vx[i][j] != vx[1][j]) can[i] = false;
            }
        }
        int ans = 1;
        for(int j=2;j<=n;j++) if(can[j]) ans++;
        cout << ans << "\n";
    }
}
