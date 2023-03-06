#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool vis[8][8];
int dx[] = {1,1,-1,-1,2,2,-2,-2};
int dy[] = {2,-2,2,-2,1,-1,1,-1};

//Warnsdorff’s algorithm
//visit unvisited node with minimum unvisited adj
int cntg = 0;
vector<pair<int,int>> ans;
int order[8][8];
bool kng(int x, int y, int cnt){
    ++cnt;
    if(cnt == 64){
        return true;
    }
    set<pair<int,int>> move;
    for(int i=0;i<8;i++){
        if(x + dx[i] < 8 && x + dx[i] >= 0 && y + dy[i] < 8 && y + dy[i] >= 0){
            if(!vis[x+dx[i]][y+dy[i]]){
                int curcnt = 0, a = x + dx[i], b = y + dy[i];
                for(int j=0;j<8;j++){
                    if(a + dx[j] < 8 && b + dy[j] < 8 && a + dx[j] >= 0 && b + dy[j] >= 0 && !vis[a+dx[j]][b+dy[j]]){
                        curcnt++;
                    }
                }
                move.insert({curcnt, i});
            }
        }
    }
    for(auto it = move.begin(); it!= move.end(); ++it){
        int nxtx = x + dx[it->second];
        int nxty = y + dy[it->second];
        vis[nxtx][nxty] = true;
        ans.emplace_back(nxtx,nxty);
        if(kng(nxtx, nxty, cnt)) return true;
        vis[nxtx][nxty] = false;
        ans.pop_back();
    }
    return false;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //test 4x4
    int x, y;
    cin >> x >> y;
    x--, y--;
    vis[x][y] = true;
    ans.emplace_back(x, y);
    kng(x, y, 0);
    for(int i=0;i<ans.size();i++){
        order[ans[i].first][ans[i].second] = i+1;
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout << order[j][i] << " \n"[j == 7];
        }
    }
}

