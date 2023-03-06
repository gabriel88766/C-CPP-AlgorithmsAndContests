#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 2505;
vector<int> adj[N];
int d[N], p[N];

int bfs(int src, int dest){
    memset(d, 63, sizeof(d)); 
    queue<int> q;
    q.push(src); 
    d[src] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(v == dest && u == src) continue;
            if(v == dest) return d[u] + 1;
            if(d[u] + 1 < d[v]){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return INF_INT;
}

 
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = INF_INT;
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++){
            int nxt = bfs(adj[i][j], i) + 1;
            ans = min(ans,nxt);
        }
    }
    if(ans < INF_INT) cout << ans;
    else cout << "-1";
}