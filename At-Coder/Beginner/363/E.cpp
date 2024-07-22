#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
const int M = 100005;
int gr[N][N];
int ans[N][N];
int qt[M];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, y;
    cin >> h >> w >> y;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
            ans[i][j] = INF_INT;
        }
    }
    priority_queue<pair<int, pair<int,int>>> pq;
    for(int i=1;i<=h;i++){
        pq.push({-gr[i][1], {i, 1}});
        pq.push({-gr[i][w], {i, w}});
    }
    for(int j=2;j<=w;j++){
        pq.push({-gr[1][j], {1, j}});
        pq.push({-gr[h][j], {h, j}});
    }
    while(!pq.empty()){
        auto [d, u] = pq.top();
        auto [x, y] = u;
        pq.pop();
        if(abs(d) >= ans[x][y]) continue;
        ans[x][y] = abs(d);
        for(int i=0;i<4;i++){
            int xd = x + dx[i];
            int yd = y + dy[i];
            if(xd < 1 || xd > h) continue;
            if(yd < 1 || yd > w) continue;
            pq.push({-max(abs(d), gr[xd][yd]), {xd, yd}});
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            qt[ans[i][j]-1]++;
        }
    }
    for(int i=M-2;i>=1;i--) qt[i] += qt[i+1];
    for(int i=1;i<=y;i++) cout << qt[i] << "\n"; 
}
