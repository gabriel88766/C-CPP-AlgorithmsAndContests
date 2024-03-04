#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


int d[3606][3606];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    memset(d, 63, sizeof(d));
    vector<vector<char>> gr(n, vector<char>(n));
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> gr[i][j];
            if(gr[i][j] == 'P') vp.push_back({i, j});
        }
    }
    pair<int,int> ini = {vp[0].first * n + vp[0].second, vp[1].first * n + vp[1].second};
    queue<pair<int,int>> q;
    q.push(ini);
    d[ini.first][ini.second ] = 0;
    while(!q.empty()){
        auto [l1, l2] = q.front();
        q.pop();
        int x1 = l1 / n, y1 = l1 % n;
        int x2 = l2 / n, y2 = l2 % n;
        for(int i=0;i<4;i++){
            int dl1 = l1, dl2 = l2;
            int di = x1 + dx[i];
            int dj = y1 + dy[i];
            bool ok = true;
            if(di < 0 || di >= n) ok = false;
            if(dj < 0 || dj >= n) ok = false;
            if(ok && gr[di][dj] == '#') ok = false;
            if(ok) dl1 = di * n + dj;
            di = x2 + dx[i];
            dj = y2 + dy[i];
            ok = true;
            if(di < 0 || di >= n) ok = false;
            if(dj < 0 || dj >= n) ok = false;
            if(ok && gr[di][dj] == '#') ok = false;
            if(ok) dl2 = di * n + dj;
            if(d[dl1][dl2] > d[l1][l2] + 1){
                d[dl1][dl2] = d[l1][l2] + 1;
                q.push({dl1, dl2});
            }
        }
    }   
    int ans = INF_INT;
    for(int i=0;i<n*n;i++){
        ans = min(ans, d[i][i]);
    }
    if(ans == INF_INT) cout << "-1\n";
    else cout << ans << "\n";
}
