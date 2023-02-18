#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int d[N], n, ans[N];

void bfs(int src){
    queue<int> q;
    q.push(src); 
    d[src] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : adj[u]){
            if(d[u] + 1 < d[v]){
                d[v] = d[u] + 1; q.push(v); ans[v] = max(ans[v], d[v]);
            }
        }
    }
}

void diameter(){ //node first to second is the diameter.
    memset(d, 63, sizeof(d));
    bfs(1);
    int fart1 = 1, maxd = 0, fart2 = 1;
    for(int i=2;i<=n;i++) if(d[i] > maxd) maxd = d[i], fart1 = i;
    memset(d, 63, sizeof(d));
    bfs(fart1);
    maxd = 0;
    for(int i=1;i<=n;i++) if(d[i] > maxd) maxd = d[i], fart2 = i;
    memset(d, 63, sizeof(d));
    bfs(fart2);
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    cin >> n;
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    diameter();
    for(int i=1;i<=n;i++) cout << ans[i ] << " ";
}
