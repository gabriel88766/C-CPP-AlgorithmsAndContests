#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {0,0,0,1,1,1,-1,-1,-1};
int dy[] = {0,1,-1,0,1,-1,0,1,-1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> grid[i][j];
        }
    }
    function<void(int,int)> dfs = [&](int x, int y){
        vis[x][y] = true;
        for(int i=0;i<=8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= h) continue;
            if(ny < 0 || ny >= w) continue;
            if(!vis[nx][ny] && grid[nx][ny] == '#'){
                dfs(nx, ny);
            }
        }
    };
    int ans = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(!vis[i][j] && grid[i][j] == '#'){
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << "\n";
}
