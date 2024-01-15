#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 505;
vector<pair<int,int>> adj[N];
int color[N];
int n, bg;
int par[N];
int node_begin_cycle;

bool dfs_cycle(int u, int p){
    color[u] = 1;
    par[u] = p;
    for(auto [i, alw] : adj[u]){
        if(!alw) continue;
        //if(i == p) continue; //uncomment if undirected.
        if(color[i] == 0 && dfs_cycle(i, u)) return true;
        else if(color[i] == 1){
            node_begin_cycle = i;
            par[i] = u;
            return true; 
        }
    }
    color[u] = 2;
    return false;
}
vector<int> find_cycle(int n){ //if returned vector is empty, then no cycle
    vector<int> ans;
    node_begin_cycle = -1;
    for(int i=1;i<=n;i++) color[i] = 0;
    for(int i=1;i<=n;i++) if(!color[i] && dfs_cycle(i, -1)) break;
    if(node_begin_cycle == -1) return ans;
    int s = node_begin_cycle, cur = node_begin_cycle;
    do{
        ans.push_back(cur);
        cur = par[cur];
    }while(cur != s);
    ans.push_back(cur);
    reverse(ans.begin(), ans.end()); //
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, 1});
    }
    auto ans = find_cycle(n);
    if(ans.size()){    
        vector<pair<int,int>> vx;
        for(int j=0;j<ans.size()-1;j++){
            auto x = ans[j];
            auto y = ans[j+1];
            for(int i=0;i<adj[x].size();i++){
                if(adj[x][i].first == y){
                    vx.push_back({x, i});
                }
            }
        }
        bool ok = false;
        for(auto [v, i] : vx){
            adj[v][i].second = 0;
            auto vec = find_cycle(n);
            if(vec.size() == 0){
                ok = true;
                break;
            }
            adj[v][i].second = 1;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }else cout << "YES\n";
}
