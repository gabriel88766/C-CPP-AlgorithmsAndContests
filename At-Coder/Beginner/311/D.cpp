#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char> (m));
    vector<vector<char>> vis(n, vector<char> (m, false));
    vector<vector<char>> used(n, vector<char> (m, false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    //BFS
    queue<pair<int,int>> q;
    q.push({1,1});
    used[1][1] = true;
    while(!q.empty()){
        auto sq = q.front();
        q.pop();
        vis[sq.first][sq.second] = true;
        for(int i=0;i<4;i++){
            auto cur = sq;
            while(v[cur.first+dx[i]][cur.second+dy[i]] == '.'){
                vis[cur.first+dx[i]][cur.second+dy[i]] = true;
                cur.first += dx[i];
                cur.second += dy[i];
            }
            if(!used[cur.first][cur.second]){ 
                q.push(cur);
                used[cur.first][cur.second] = true;
            }
        }
    }


    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans += vis[i][j] ? 1 : 0;
        }
    }
    cout << ans;
}
