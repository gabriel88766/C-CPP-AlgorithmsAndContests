#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 2e5+3;
int d[N], p[N];
vector<int> adj[N];

void bfs(int src){
    memset(d, 63, sizeof(d)); //this line must be skipped if multiples bfs
    queue<int> q;
    q.push(src); 
    d[src] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[u] + 1 < d[v]){
                d[v] = d[u] + 1;
                p[v] = u;
                q.push(v);
            }
        }
    }
}

//to find path

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
    int src = 1, dest = n, cur;
    bfs(src);
    if(d[dest] != INF_INT){
        cur = dest;
        vector<int> ans;
        while(cur != src){
            ans.push_back(cur);
            cur = p[cur];
        }
        ans.push_back(src);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for(auto i : ans) cout << i << " ";
    }else cout << "IMPOSSIBLE";
}
