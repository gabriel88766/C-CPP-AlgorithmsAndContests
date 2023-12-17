#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
double dp[101][8][8][8][8];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            dp[0][i][j][i][j] = 1;
        }
    }
    int k;
    cin >> k;
    for(int nw=1;nw<=k;nw++){
        for(int xx=0;xx<8;xx++){
            for(int yy=0;yy<8;yy++){
                for(int i=0;i<8;i++){ //robot xx, yy from i, j
                    for(int j=0;j<8;j++){
                        int c = 0;
                        for(int mv=0;mv<4;mv++){
                            int x = i + dx[mv];
                            int y = j + dy[mv];
                            if(x >= 8 || x < 0 || y >= 8 || y < 0) continue;
                            c++;
                        }
                        for(int mv=0;mv<4;mv++){
                            int x = i + dx[mv];
                            int y = j + dy[mv];
                            if(x >= 8 || x < 0 || y >= 8 || y < 0) continue;
                            dp[nw][xx][yy][x][y] += dp[nw-1][xx][yy][i][j]/c;
                        }
                    }
                }
            }
        }
    }
    double ans = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            //probability i, j empty
            double cur = 1;
            for(int xx=0;xx<8;xx++){
                for(int yy=0;yy<8;yy++){
                    cur *= (1-dp[k][xx][yy][i][j]);
                }
            }
            ans += cur;
        }
    }
    cout << fixed << setprecision(6) << ans << "\n";

}
