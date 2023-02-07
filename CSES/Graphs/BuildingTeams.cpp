#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;

using namespace std;

const int N = 2e5+3;
int c[N]; // 0 OR 1
vector<int> adj[N];
const int INF_INT = 0x3f3f3f3f;

bool bfs_bipartite(int src){
    queue<int> q;
    q.push(src); 
    c[src] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(c[v] == c[u]) return false;
            if(c[v] == INF_INT){
                c[v] = c[u] ^ 1;
                q.push(v);
            }
        }
    }
    return true;
}

bool isbiparitite(int n){
    memset(c, 63, sizeof(c));
    for(int i=1;i<=n;i++) if(c[i] == INF_INT && !bfs_bipartite(i)) return false;
    return true;
}

//cout << fixed << setprecision(6) //bipartite
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
    if(isbiparitite(n)) for(int i=1;i<=n;i++) cout << c[i] + 1 << " ";
    else cout << "IMPOSSIBLE";
    
}
