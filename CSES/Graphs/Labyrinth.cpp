#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;


const int N = 1e3+4;
int d[N][N];
char matrix[N][N];
pair<int,int> p[N][N];
vector<pair<int,int>> adj[N][N];

void bfs(pair<int,int> src){
    memset(d, 63, sizeof(d)); 
    queue<pair<int,int>> q;
    q.push(src); 
    d[src.first][src.second] = 0;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : adj[u.first][u.second]){
            if(d[u.first][u.second] + 1 < d[v.first][v.second]){
                p[v.first][v.second] = u;
                d[v.first][v.second] = d[u.first][u.second] + 1;
                q.push(v);
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    pair<int,int> src, dest;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 'A') src = {i, j};
            if(matrix[i][j] == 'B') dest = {i, j};
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(matrix[i][j] != '#'){
                if(matrix[i+1][j] != '#') adj[i][j].push_back({i+1, j}); 
                if(matrix[i][j+1] != '#') adj[i][j].push_back({i, j+1}); 
                if(matrix[i][j-1] != '#') adj[i][j].push_back({i, j-1}); 
                if(matrix[i-1][j] != '#') adj[i][j].push_back({i-1, j}); 
            }
        }
    }
    bfs(src);
    if(d[dest.first][dest.second] != INF_INT){
        cout << "YES\n" << d[dest.first][dest.second] << "\n";
        pair<int,int> cur = dest;
        string ans;
        while(cur != src){
            auto nxt = p[cur.first][cur.second];
            if(nxt.second == (cur.second+1)) ans += 'L';
            if(nxt.second == (cur.second-1)) ans += 'R';
            if(nxt.first == (cur.first+1)) ans += 'U';
            if(nxt.first == (cur.first-1)) ans += 'D';
            cur = nxt; 
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }else{
        cout << "NO";
    }
}
