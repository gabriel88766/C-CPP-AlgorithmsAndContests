#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char gr[505][505];
bool vis[505][505][5];
char sn[] = "snuke";
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
        }
    }
    queue<tuple<int, int, int>> qp;
    if(gr[1][1] == 's'){
        qp.push({1, 1, 0});
        vis[1][1][0] = true;
    }
    while(!qp.empty()){
        auto [x, y, l] = qp.front();
        qp.pop();
        int nl = (l + 1) % 5;
        for(int k=0;k<4;k++){
            int xd = x + dx[k];
            int yd = y + dy[k];
            if(gr[xd][yd] == sn[nl] && vis[xd][yd][nl] == false){
                vis[xd][yd][nl] = true;
                qp.push({xd, yd, nl});
            }
        }
    }
    bool ok = false;
    for(int j=0;j<5;j++) if(vis[h][w][j]) ok = true;
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
