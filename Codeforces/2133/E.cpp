#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N], adj2[N];
int qt[N];
bool isel[N];
vector<int> elv;

void dfs(int u, int p){
    qt[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            qt[u] += qt[v];
        }
    }
    if(qt[u] > 3){
        elv.push_back(u);
        qt[u] = 0;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0);
        assert(elv.size() <= n/4); //something is wrong 1
        vector<pair<int, int>> ans;
        vector<bool> vis(n+1);
        for(auto x : elv){
            vis[x] = true;
            ans.push_back({x, 1});
            ans.push_back({x, 2});
            isel[x] = true;
        }
        for(int i=1;i<=n;i++){
            if(isel[i]) continue;
            for(auto  v : adj[i]){
                if(isel[v]) continue;
                adj2[i].push_back(v);
            }
        }   
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(adj2[i].size() == 2){
                    int u = adj2[i][0], v = adj2[i][1];
                    assert(adj2[u].size() == 1 && adj2[v].size() == 1); //something is wrong 2
                    ans.push_back({u, 1});
                    ans.push_back({i, 1});
                    ans.push_back({v, 1});
                    vis[u] = vis[i] = vis[v] = true;
                }else if(adj2[i].size() == 1){
                    int u = adj2[i][0];
                    if(adj2[u].size() == 1){
                        vis[u] = vis[i] = true;
                        ans.push_back({i, 1});
                        ans.push_back({u, 1});
                    }else if(adj2[u].size() == 2){
                        int v;
                        if(adj2[u][0] == i) v = adj2[u][1];
                        else v = adj2[u][0];
                        assert(adj2[v].size() == 1); //something is wrong 3;
                        ans.push_back({i, 1});
                        ans.push_back({u, 1});
                        ans.push_back({v, 1});
                        vis[u] = vis[i] = vis[v] = true;
                    }else assert(false); //something is wrong 4
                }else if(adj2[i].size() == 0){
                    ans.push_back({i, 1});
                    vis[i] = true;
                }else assert(false); //something is wrong 5
            }
        }

        //ans
        cout << ans.size() << "\n";
        for(auto [a, b]: ans) cout << b << " " << a << "\n";
        //clear
        elv.clear();
        for(int i=1;i<=n;i++){
            adj[i].clear();
            qt[i] = 0;
            isel[i] = false;
            adj2[i].clear();
        }
    }
}
