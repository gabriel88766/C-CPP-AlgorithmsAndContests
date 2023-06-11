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
    int minx = 505, maxx = 0, miny = 505, maxy = 0;
    int x, y;
    cin >> x >> y;
    vector<vector<char>> grid(x+1, vector<char>(y+1));
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            cin >> grid[i][j];
            if(grid[i][j] == '#'){
                maxx = max(maxx, i);
                minx = min(minx, i);
                maxy = max(maxy, j);
                miny = min(miny, j);
            }
        }  
    }
    for(int i=minx;i<=maxx;i++){
        for(int j=miny; j<=maxy; j++){
            if(grid[i][j] != '#'){
                cout << i << " " << j << "\n";
            }
        }
    }
}
