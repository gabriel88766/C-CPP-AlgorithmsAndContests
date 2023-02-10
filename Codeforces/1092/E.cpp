#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
vector<int> adj[N];
bool vis[N];
int cmp[N], d[N], cn = 0, diam[N], rt[N];
vector<int> cmpn[N];

void dfs(int u){
    cmpn[cn].push_back(u);
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void bfs(int src){
    queue<int> q;
    q.push(src); 
    d[src] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[u] + 1 < d[v]){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, x, maxd;
    cin >> n >> x;
    vector<pair<int,int>> ans;
    for(int i=0;i<x;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(x != (n-1)){
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                cmp[++cn] = i;
                dfs(i);
            }
        }

        for(int i=1;i<=n;i++) vis[i] = false;
        memset(d, 63, sizeof(d));
        int on = 0;
        for(int i=1;i<=n;i++){
            if(d[i] == INF_INT){
                ++on;
                bfs(i);
                int maxd = -INF_INT, fart;
                for(int j=0;j<cmpn[on].size();j++){
                    if(d[cmpn[on][j]] > maxd) maxd = d[cmpn[on][j]], fart = cmpn[on][j]; 
                    d[cmpn[on][j]] = INF_INT;
                }
                bfs(fart);
                maxd = 0;
                for(int j=0;j<cmpn[on].size();j++){
                    if(d[cmpn[on][j]] > maxd) maxd = d[cmpn[on][j]];
                }
                for(int j=0;j<cmpn[on].size();j++){
                    if(d[cmpn[on][j]] == maxd/2){
                        rt[on] = cmpn[on][j];
                        break;
                    }
                }
                diam[on] = maxd;
            }
        }

        for(int i=1;i<=n;i++)  d[i] = INF_INT;
        int ch = 0, maxd = -1;
        for(int i=1;i<=on;i++){
            if(maxd < diam[i]){
                maxd = diam[i];
                ch = i;
            }
        }
        for(int i=1;i<=on;i++){
            if(i == ch) continue;
            ans.push_back({rt[i], rt[ch]});
            adj[rt[i]].push_back(rt[ch]);
            adj[rt[ch]].push_back(rt[i]);
        }
    }
    int ansd, fart2;
    memset(d, 63, sizeof(d));
    maxd = -1;
    bfs(1);
    cout << endl;
    for(int i=1;i<=n;i++) if(maxd < d[i]) maxd = d[i], fart2 = i;
    memset(d, 63, sizeof(d));
    bfs(fart2);
    for(int i=1;i<=n;i++) if(maxd < d[i]) maxd = d[i];
    cout << maxd << "\n";
    if(!ans.empty()) for(auto u : ans) cout << u.first << " " << u.second << "\n";
}
