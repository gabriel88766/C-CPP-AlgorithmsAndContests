#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 55;
int adj[N][N];
vector<pair<int,int>> edgs;
bool vis[N];

void dfs(int u){
    vis[u] = true;
    for(int i=1;i<=50;i++){
        if(!vis[i] && adj[u][i]) dfs(i);
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
        edgs.push_back({a,b});
    }
    int cnt = 0;
    for(int i=0;i<m;i++){
        int a = edgs[i].first, b = edgs[i].second;
        memset(vis, 0, sizeof(vis));
        adj[a][b] = adj[b][a] = 0;
        dfs(1);
        bool ok = true;
        for(int i=1;i<=n;i++) if(!vis[i]) ok = false;
        if(ok) cnt++;
        adj[a][b] = adj[b][a] = 1;
    }
    cout << m-cnt;
}
