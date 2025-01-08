#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
char gr[N][N];
int d[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    pair<int,int> s, g;
    memset(gr, '#', sizeof(gr));
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
            if(gr[i][j] == 'S') s ={i, j};
            if(gr[i][j] == 'G') g = {i, j};
        }
    }
    auto bfs = [&](int x){
        int f0 = x ? 0 : 2;
        memset(d, 63, sizeof(d));
        d[s.first][s.second] = 0;
        queue<pair<int,int>> q;
        q.push(s);
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            int cx = d[x][y] % 2 ? f0 : (f0 ^ 2);
            for(int k=cx;k<cx+2;k++){
                int xd = x + dx[k];
                int yd = y + dy[k];
                if(gr[xd][yd] != '#' && d[xd][yd] > d[x][y] + 1){
                    d[xd][yd] = d[x][y] + 1;
                    q.push({xd, yd});
                }
            }
        }
    };
    int ans = INF_INT;
    bfs(0);
    ans = min(ans, d[g.first][g.second]);
    bfs(2);
    ans = min(ans, d[g.first][g.second]);
    if(ans != INF_INT) cout << ans << "\n";
    else cout << "-1\n";
}
