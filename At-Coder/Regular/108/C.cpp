#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N], adjc[N];
int ans[N], vis[N];

void dfs(int u, int p, int col){
    vis[u] = true;
    if(ans[p] == col){
        if(col == 1) ans[u] = 2;
        else ans[u] = 1;
    }else ans[u] = col;
    for(int i=0;i<adj[u].size();i++){
        if(!vis[adj[u][i]]){
            dfs(adj[u][i], u, adjc[u][i]);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adjc[a].push_back(c);
        adj[b].push_back(a);
        adjc[b].push_back(c);
    }
    ans[0] = -1;
    dfs(1, 0, -1);
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
}
