#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> adj[101];
bool vis[101];
vector<int> ans;

void dfs(int u){
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs(i);
        }
    }
    ans.push_back(u);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for(int i=0;i<m;i++) cin >> v[i];
    for(int i=0;i<m;i++){
        adj[v[i]].push_back(v[i]+1);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    for(auto u : ans) cout << u << " ";
}
