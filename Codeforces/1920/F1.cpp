#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, qr;
    cin >> n >> m >> qr;
    vector<vector<bool>> forb(n+1, vector<bool>(m+1));
    vector<vector<int>> d(n+1, vector<int>(m+1, INF_INT));
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin >> c;
            if(c == 'v'){
                q.push({i, j});
                d[i][j] = 0;
            }else if(c == '#') forb[i][j] = true;
        }
    }
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xd = x + dx[i];
            int yd = y + dy[i];
            if(xd >= 1 && xd <= n && yd >= 1 && yd <= m){
                if(d[xd][yd] > d[x][y] + 1){
                    d[xd][yd] = d[x][y] + 1;
                    q.push({xd, yd});
                }
            }
        }
    }


    for(int i=0;i<qr;i++){
        int xi, yi;
        cin >> xi >> yi;
        int lo = 0, hi = d[xi][yi];
        while(lo != hi){
            int mid = lo + (hi - lo + 1)/2;
            q.push({xi, yi});
            bool ok = true;
            vector<vector<bool>> vis(n+1, vector<bool>(m+1, false));
            vis[xi][yi] = true;
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int xd = x + dx[j];
                    int yd = y + dy[j];
                    if(xd >= 1 && xd <= n && yd >= 1 && yd <= m){
                        if(forb[xd][yd]) continue;
                        if(d[xd][yd] >= mid && !vis[xd][yd]){
                            vis[xd][yd] = true;
                            q.push({xd, yd});
                        }
                    }
                }
            }
            vector<vector<bool>> vis2(n+1, vector<bool>(m+1, false));
            //after mark all, try to scape from island
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(forb[i][j]){
                        q.push({i, j});
                        vis2[i][j] = true;
                    }
                }
            }
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                for(int j=0;j<8;j++){
                    int xd = x + dx[j];
                    int yd = y + dy[j];
                    if(xd >= 1 && xd <= n && yd >= 1 && yd <= m){
                        if(!vis2[xd][yd] && !vis[xd][yd]){
                            vis2[xd][yd] = true;
                            q.push({xd, yd});
                        }
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(i == 1 || i == n || j == 1 || j == m){
                        if(vis2[i][j]){
                            ok = false;
                        }
                    }
                }
            }
            if(ok) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << "\n";
    }
}