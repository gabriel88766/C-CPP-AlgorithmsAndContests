#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 505;
int ds[N][N][2];
char gr[N][N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(ds, 63, sizeof(ds));
    memset(gr, '#', sizeof(gr));
    int h, w;
    cin >> h >> w;
    pair<int, int> src, dst;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
            if(gr[i][j] == 'S'){
                src = {i, j};
            }
            if(gr[i][j] == 'G'){
                dst = {i, j};
            }
        }
    }
    queue<tuple<int, int, int>> q;
    q.push({src.first, src.second, 0});
    ds[src.first][src.second][0] = 0;
    while(q.size()){
        auto [x, y, j] = q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int xd = x + dx[k];
            int yd = y + dy[k];
            if(gr[xd][yd] == '#') continue; //never can
            if(gr[xd][yd] == 'o' || gr[xd][yd] == 'x'){
                bool ok = false;
                if(gr[xd][yd] == 'o' && j == 0){
                    ok = true;
                }else if(gr[xd][yd] == 'x' && j == 1){
                    ok = true;
                }
                if(ok && ds[xd][yd][j] > ds[x][y][j] + 1){
                    ds[xd][yd][j] = ds[x][y][j] + 1;
                    q.push({xd, yd, j});
                }
            }else if(gr[xd][yd] == '?'){
                if(ds[xd][yd][j^1] > ds[x][y][j] + 1){
                    ds[xd][yd][j^1] = ds[x][y][j] + 1;
                    q.push({xd, yd, j^1});
                }
            }else{
                if(ds[xd][yd][j] > ds[x][y][j] + 1){
                    ds[xd][yd][j] = ds[x][y][j] + 1;
                    q.push({xd,yd,j});
                }
            }
        }
    }
    if(ds[dst.first][dst.second][0] < INF_INT || ds[dst.first][dst.second][1] < INF_INT){
        cout << min(ds[dst.first][dst.second][0], ds[dst.first][dst.second][1]) << "\n";
    }else cout << "-1\n";
}
