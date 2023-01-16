//Find Cycle.

#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 1e5+3;
vector<int> adj[N];
int par[N], match = -1;
int color[N];

bool dfs(int u, int p){
    par[u] = p;
    color[u] = 1;
    for(auto v : adj[u]){
        if(color[v] == 1){
            match = v;
            par[v] = u;
            return true;
        }else if(color[v] == 0 && dfs(v, u)) return true;
        
    }
    color[u] = 2;
    return false;
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
    }
    for(int i=1;i<=n;i++){
        if(!color[i] && dfs(i, 0)) break;
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
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for(auto i : ans) cout << i << " ";
    }
}
