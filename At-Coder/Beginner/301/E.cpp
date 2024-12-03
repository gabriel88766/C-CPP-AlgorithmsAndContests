#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 305;
char gr[N][N];
int d[20][N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dp[1 << 20][20];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, t;
    cin >> h >> w >> t;
    memset(gr, '#', sizeof(gr));
    memset(d, 63, sizeof(d));
    memset(dp, 63, sizeof(dp));
    assert(gr[0][0] == '#');
    pair<int,int> S, G;
    vector<pair<int,int>> auxv;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
            if(gr[i][j] == 'S') S = {i, j};
            if(gr[i][j] == 'G') G = {i, j};
            if(gr[i][j] == 'o') auxv.push_back({i, j});
        }
    }
    vector<pair<int,int>> vp;
    vp.push_back(S);
    for(auto x : auxv) vp.push_back(x);
    vp.push_back(G);
    for(int i=0;i<vp.size();i++){
        auto src = vp[i];
        d[i][src.first][src.second] = 0;
        queue<pair<int,int>> q;
        q.push(src);
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int xd = x + dx[k];
                int yd = y + dy[k];
                if(gr[xd][yd] != '#' && d[i][xd][yd] > d[i][x][y] + 1){
                    d[i][xd][yd] = d[i][x][y] + 1;
                    q.push({xd, yd});
                }
            }
        }
    }
    int n = vp.size();
    if(d[0][G.first][G.second] <= t){
        int ans = 0;
        dp[1][0] = 0;
        for(int i=0;i<(1 << n);i++){
            for(int j=0;j<n;j++){
                if(dp[i][j] <= t){
                    if(j == n-1){
                        ans = max(ans, __builtin_popcount(i) - 2);
                    }
                    for(int k=0;k<n;k++){
                        if(i & (1 << k)) continue;
                        dp[i | 1 << k][k] = min(dp[i | 1 << k][k], dp[i][j] + d[j][vp[k].first][vp[k].second]);
                    }
                }
            }
        }
        cout << ans << "\n";
    }else cout << "-1\n";
}
