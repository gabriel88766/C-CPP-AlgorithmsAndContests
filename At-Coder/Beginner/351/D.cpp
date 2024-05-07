#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    vector<string> gr(h);
    for(int i=0;i<h;i++) cin >> gr[i];
    vector<vector<int>> vis(h, vector<int>(w, 0));
    int ans = 1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(!vis[i][j] && gr[i][j] == '.'){
                bool ok = true;
                if(i+1 < h && gr[i+1][j] == '#') ok = false;
                if(i-1 >= 0 && gr[i-1][j] == '#') ok = false;
                if(j+1 < w && gr[i][j+1] == '#') ok = false;
                if(j-1 >= 0 && gr[i][j-1] == '#') ok = false;
                if(ok){
                    //bfs
                    int cnt = 0;
                    vector<pair<int,int>> vp;
                    queue<pair<int,int>> qp;
                    qp.push({i, j});
                    vis[i][j] = 1;
                    while(!qp.empty()){
                        cnt++;
                        auto [x, y] = qp.front();
                        qp.pop();
                        bool ok = true;
                        if(x+1 < h && gr[x+1][y] == '#') ok = false;
                        if(x-1 >= 0 && gr[x-1][y] == '#') ok = false;
                        if(y+1 < w && gr[x][y+1] == '#') ok = false;
                        if(y-1 >= 0 && gr[x][y-1] == '#') ok = false;
                        if(ok){
                            if(x+1 < h && !vis[x+1][y]){
                                qp.push({x+1, y});
                                vis[x+1][y] = 1;
                            }
                            if(x-1 >= 0 && !vis[x-1][y]){
                                qp.push({x-1, y});
                                vis[x-1][y] = 1;
                            }
                            if(y+1 < w && !vis[x][y+1]){
                                qp.push({x, y+1});
                                vis[x][y+1] = 1;
                            }
                            if(y-1 >= 0 && !vis[x][y-1]){
                                qp.push({x, y-1});
                                vis[x][y-1] = 1;
                            }
                        }else{
                            vp.push_back({x, y});
                        }
                    }
                    ans = max(ans, cnt);
                    for(auto [x, y] : vp) vis[x][y] = 0;
                }
            }
        }
    }
    cout << ans << "\n";
}   
