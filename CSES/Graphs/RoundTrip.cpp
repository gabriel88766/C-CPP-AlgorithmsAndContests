//Find Cycle.

#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 1e5+3;
vector<int> adj[N];
int par[N], match = -1;
char visited[N];

void dfs(int u, int p){
    par[u] = p;
    visited[u] = true;
    for(auto v : adj[u]){
        if(match != -1) return;
        if(visited[v] && (v != p)){
            match = v;
            par[v] = u;
            return;
        }else if(!visited[v]) dfs(v, u);
        
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs(i, 0);
    }
    if(match == -1) cout << "IMPOSSIBLE";
    else{
        int cur = match;
        vector<int> ans;
        ans.push_back(cur);
        do{
            cur = par[cur];
            ans.push_back(cur);
        }while(cur != match);
        cout << ans.size() << "\n";
        for(auto i : ans) cout << i << " ";
    }
}
