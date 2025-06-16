#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, t;
    cin >> h >> w >> t;
    vector<vector<char>> gr(h, vector<char>(w));
    int xg, yg, xs, ys;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> gr[i][j];
            if(gr[i][j] == 'G'){
                xg = i; yg = j;
            }
            if(gr[i][j] == 'S'){
                xs = i, ys = j;
            }
        }
    }
    int lo = 1, hi = 1e9;
    while(lo != hi){
        vector<vector<ll>> dp(h, vector<ll>(w, INF_LL));
        vector<vector<bool>> vis(h, vector<bool>(w, false));
        dp[xs][ys] = 0;
        int mid = lo + (hi - lo + 1)/2;
        for(int xx = 0; xx < h*w; xx++){
            int u = -1, v = -1;
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    if(vis[i][j] == false){
                        if(u == -1) u = i, v = j;
                        else if(dp[u][v] > dp[i][j]) u = i, v = j;
                    }
                }
            }
            vis[u][v] = true;
            for(int i=0;i<4;i++){
                int xd = u + dx[i];
                int yd = v + dy[i];
                if(xd >= 0 && xd < h && yd >= 0 && yd < w && dp[xd][yd] > dp[u][v] + (gr[xd][yd] == '#' ? mid : 1)){
                    dp[xd][yd] = dp[u][v] + (gr[xd][yd] == '#' ? mid : 1);
                }
            }
        }
        if(dp[xg][yg] <= t) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}
