#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char grid[51][51];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> grid[i][j];
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(grid[i][j] == '*'){
                    int cur = i;
                    while(cur < n && grid[cur+1][j] == '.'){
                        swap(grid[cur][j], grid[cur+1][j]);
                        cur++;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }
}
