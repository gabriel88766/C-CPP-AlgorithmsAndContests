#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e3+2;
int n, m, w;
vector<vector<ll>> d1(N, vector<ll>(N, INF_LL));
vector<vector<ll>> d2(N, vector<ll>(N, INF_LL));
vector<vector<ll>> gr(N, vector<ll>(N));
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
void bfs(vector<vector<ll>> &d, pair<int,int> src){
    queue<pair<int,int>> qp;
    d[src.first][src.second] = 0;
    qp.push(src);
    while(!qp.empty()){
        auto [x, y] = qp.front();
        qp.pop();
        for(int i=0;i<4;i++){
            int di = x + dx[i];
            int dj = y + dy[i];
            if(di < 1 || di > n) continue;
            if(dj < 1 || dj > m) continue;
            if(gr[di][dj] == -1) continue;
            if(d[di][dj] > d[x][y] + w){
                d[di][dj] = d[x][y] + w;
                qp.push({di, dj});
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> m >> w;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> gr[i][j];
        }
    }
    bfs(d1, {1,1});
    bfs(d2, {n, m});
    ll ans = d2[1][1];
    ll a1 = INF_LL, a2 = INF_LL;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(gr[i][j] > 0){
                a1 = min(a1, d1[i][j] + gr[i][j]);
                a2 = min(a2, d2[i][j] + gr[i][j]);
            }
        }
    }
    ans = min(ans, a1+a2);
    if(ans != INF_LL) cout << ans << "\n";
    else cout << "-1\n";
}
