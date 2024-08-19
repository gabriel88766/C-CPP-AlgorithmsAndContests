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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n+2, vector<int>(m+2));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> v[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int mv = 0;
                mv = max(mv, v[i][j-1]);
                mv = max(mv, v[i][j+1]);
                mv = max(mv, v[i+1][j]);
                mv = max(mv, v[i-1][j]);
                v[i][j] = min(v[i][j], mv);
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
        
    }
}
