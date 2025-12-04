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
        int n;
        cin >> n;
        int p = 0;
        //simulation
        vector<vector<int>> v(n+2, vector<int>(n+2));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                v[i][j] = ++p;
            }
        }
        int mx = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mx = max(mx, v[i][j] + v[i-1][j] + v[i+1][j] + v[i][j+1] + v[i][j-1]);
            }
        }
        cout << mx << "\n";
    }
}
