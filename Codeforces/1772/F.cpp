#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


vector<int> adj[102];
vector<vector<pair<int,int>>> vp[102];//changes to make adj[i][0] edge
bool vis[102];

char v[102][31][31];

void dfs(int u){
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1;i<=(k+1);i++){
        for(int j=0;j<n;j++){
            for(int w=0;w<m;w++){
                cin >> v[i][j][w];
            }
        }
    }
    if(!k){
        cout << "1\n0";
        return 0;
    }
    for(int i=1;i<=(k+1);i++){
        for(int d=1;d<=(k+1); d++){
            if(i == d) continue;
            vector<pair<int,int>> ops;
            bool ok = true;
            for(int j=1;j<(n-1);j++){
                if(!ok) break;
                for(int w=1;w<(m-1);w++){
                    if(!ok) break;
                    if(v[i][j][w] != v[d][j][w]){
                        if(v[i][j][w+1] == v[i][j][w]) ok = false;
                        if(v[i][j][w-1] == v[i][j][w]) ok = false;
                        if(v[i][j-1][w] == v[i][j][w]) ok = false;
                        if(v[i][j+1][w] == v[i][j][w]) ok = false;
                        if(ok) ops.push_back({j+1, w+1});
                    }
                }
            }
            if(ok){
                adj[i].push_back(d);
                vp[i].push_back(ops);
            }
        }
    }
    int ans;
    for(int i=1;i<=(k+1);i++){
        if(!vis[i]){
            ans = i;
            dfs(i);
        }
    }
    for(int i=1;i<=(k+1);i++) vis[i] = false;
    int totalind = 1;
    cout << ans << "\n";
    vector<pair<int,int>> queries;
    int cur = ans;
    while(totalind != (k+1)){
        int nxt, minop = 1000;
        vis[cur] = true;
        for(int i=0;i<adj[cur].size();i++){
            if(vp[cur][i].size() < minop && !vis[adj[cur][i]]){
                minop = vp[cur][i].size();
                nxt = i;
            }
        }
        if(vp[cur][nxt].size()){
            for(auto u : vp[cur][nxt]){
                queries.push_back(u);
            }
        }
        cur = adj[cur][nxt];
        queries.push_back({cur, 0});
        totalind++;
    }
    cout << queries.size() << "\n";
    for(auto nxt : queries){
        if(nxt.second == 0) cout << "2 " << nxt.first << "\n";
        else cout << "1 " << nxt.first << " " << nxt.second << "\n";
    }
}
