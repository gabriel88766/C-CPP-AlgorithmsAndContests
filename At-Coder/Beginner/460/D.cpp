#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    vector<string> vs(h);
    for(int i=0;i<h;i++) cin >> vs[i];
    auto do_move = [&](){
        vector<string> aux(h, string(w, '.'));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(vs[i][j] == '#'){
                    continue;
                }
                for(int k=0;k<8;k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni >= 0 && ni < h && nj >= 0 && nj < w && vs[ni][nj] == '#'){
                        aux[i][j] = '#';
                    }
                }
            }
        }
        vs = aux;
    };
    do_move();
    do_move();
    vector<vector<int>> dst(h, vector<int>(w, INF_INT));
    queue<pair<int, int>> qp;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(vs[i][j] == '#'){
                dst[i][j] = 0;
                qp.push({i, j});
            }
        }
    }
    while(qp.size()){
        auto [x, y] = qp.front();
        qp.pop();
        for(int k=0;k<8;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && nx < h && ny >= 0 && ny < w && dst[nx][ny] == INF_INT){
                dst[nx][ny] = dst[x][y] + 1;
                qp.push({nx, ny});
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(dst[i][j] != INF_INT && dst[i][j] % 2 == 0){
                vs[i][j] = '#';
            }else vs[i][j] = '.';
        }
    }
    for(int i=0;i<h;i++) cout << vs[i] << "\n";
}
