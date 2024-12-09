#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char gr[1005][1005];
int d[1005][1005];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(d, 63, sizeof(d));
    int h, w, md;
    cin >> h >> w >> md;
    queue<pair<int,int>> q;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
            if(gr[i][j] == 'H'){
                q.push({i, j});
                d[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xd = x + dx[i];
            int yd = y + dy[i];
            if(gr[xd][yd] == '.' && d[xd][yd] > d[x][y] + 1){
                d[xd][yd] = d[x][y] + 1;
                q.push({xd, yd});
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(d[i][j] <= md) ans++;
        }
    }
    cout << ans << "\n";
}
