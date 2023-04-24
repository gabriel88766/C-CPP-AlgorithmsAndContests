#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int d[51][51];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    memset(d, 63, sizeof(d));
    vector<vector<char>> v(n+2, vector<char>(m+2));
    int cw = 0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
         cin >> v[i][j];
         if(v[i][j] == '.') cw++;
    }
    d[1][1] = 1;
    queue<pair<int,int>> q;
    q.push({1,1});
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            auto x = u;
            x.first += dx[i]; x.second += dy[i];
            if(v[x.first][x.second] != '.') continue;
            if(d[x.first][x.second] > d[u.first][u.second]+1){
                d[x.first][x.second] = d[u.first][u.second]+1;
                q.push(x);
            }
        }
    }
    if(d[n][m] == INF_INT) cout << "-1\n";
    else cout << cw - d[n][m];

}
