#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool lit[1505][1505][4];
bool blk[1505][1505];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //multisource floodfill
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    queue<tuple<int, int, int>> qp;
    for(int i=1;i<=n;i++){
        int x, y;
        cin >> x >> y;
        lit[x][y][0] = lit[x][y][1] = lit[x][y][2] = lit[x][y][3] = true;
        qp.push({x, y, 0});
        qp.push({x, y, 1});
        qp.push({x, y, 2});
        qp.push({x, y, 3});
    }
    for(int i=0;i<=h+1;i++){
        for(int j=0;j<=w+1;j++){
            if(i == 0 || i == h+1 || j == 0 || j == w+1) blk[i][j] = true;
        }
    }
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        blk[x][y] = true;
    }
    while(qp.size()){
        auto [x, y, dir] = qp.front();
        qp.pop();
        int xd = x + dx[dir];
        int yd = y + dy[dir];
        if((!lit[xd][yd][dir]) && (!blk[xd][yd])){
            lit[xd][yd][dir] = true;
            qp.push({xd, yd, dir});
        }
    }
    int ans = 0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(lit[i][j][0] || lit[i][j][1] || lit[i][j][2] || lit[i][j][3]) ans++;
        }   
    }
    cout << ans << "\n";
}
