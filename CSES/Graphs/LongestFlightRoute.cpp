#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N];
bool vis[N];
vector<int> topo;

void dfs(int u){
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs(i);
        }
    }
    topo.push_back(u);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs(1);
    if(!vis[n]){
        cout << "IMPOSSIBLE";
    }else{
        //solve
        reverse(topo.begin(), topo.end());
        vector<int> ans(n+1), par(n+1);
        ans[1] = 1; 
        for(auto i : topo){
            for(auto v : adj[i]){
                if(ans[v] <= ans[i]){
                    ans[v] = ans[i]+1;
                    par[v] = i;
                }
            }
        }
        int aux = n;
        vector<int> route;
        while(aux != 1){
            route.push_back(aux);
            aux = par[aux];
        }
        route.push_back(1);
        reverse(route.begin(),route.end());
        cout << ans[n] << "\n";
        for(auto x: route) cout << x << " ";
    }
}
