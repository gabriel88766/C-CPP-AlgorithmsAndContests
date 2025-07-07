#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


char gr[22][22];
int d[22][22];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(gr, '#', sizeof(gr));
    int h, w;
    cin >> h >> w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
        }
    }
    int ans = 0;
    for(int si=1;si<=h;si++){
        for(int sj=1;sj<=w;sj++){
            for(int di=1;di<=h;di++){
                for(int dj=1;dj<=w;dj++){
                    if(gr[di][dj] != '.' || gr[si][sj] != '.') continue;
                    memset(d, 63, sizeof(d));
                    queue<pair<int, int>> q;
                    q.push({si, sj});
                    d[si][sj] = 0;
                    while(q.size()){
                        auto [x, y] = q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int xd = x + dx[k];
                            int yd = y + dy[k];
                            if(gr[xd][yd] == '.' && d[xd][yd] == INF_INT){
                                d[xd][yd] = d[x][y] + 1;
                                q.push({xd, yd});
                            }
                        }
                    }
                    ans = max(ans, d[di][dj]);
                }
            }
        }
    }
    cout << ans << "\n";
}
