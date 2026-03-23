#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1,-1, 0, 0};
char gr[1002][1002];
bool vis[1002][1002];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(gr, '.', sizeof(gr));
    int h, w;
    cin >> h >> w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
        }
    }
    auto do_bfs = [&](int x, int y){
        queue<pair<int, int>> qp;
        qp.push({x, y});
        while(qp.size()){
            auto [x, y] = qp.front();
            qp.pop();
            for(int k=0;k<4;k++){
                int xd = x + dx[k];
                int yd = y + dy[k];
                if(xd >= 0 && xd <= h+1 && yd >= 0 && yd <= w+1 && gr[xd][yd] == '.' && vis[xd][yd] == false){
                    vis[xd][yd] = true;
                    qp.push({xd, yd});
                }
            }
        }
    };
    do_bfs(0, 0);
    int ans = 0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(gr[i][j] == '.' && vis[i][j] == false){
                do_bfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << "\n";
}
