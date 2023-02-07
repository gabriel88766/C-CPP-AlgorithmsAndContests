#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

set<int> valsb, valsa;
int n, a, b;

const int N = 2e5+3;
vector<int> adj[N], adjw[N];
bool vis[N];

void dfsa(int u, int x = 0){
    vis[u] = true;
    valsa.insert(x);
    for(int i=0;i<adj[u].size();i++){
        //cout << adj[u][i] << " hihi " << u <<  "\n";
        if(!vis[adj[u][i]] && adj[u][i] != b){
            dfsa(adj[u][i], x ^ adjw[u][i]);
        }
    }
}

void dfsb(int u, int x = 0){
    vis[u] = true;
    if(u != b) valsb.insert(x);
    for(int i=0;i<adj[u].size();i++){
        if(!vis[adj[u][i]]){
            dfsb(adj[u][i], x ^ adjw[u][i]);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        valsa.clear();
        valsb.clear();
        for(int i=1;i<n;i++){
            int u,v,w;
            cin >> u >> v >> w;
            adj[u].push_back(v);
            adjw[u].push_back(w);
            adj[v].push_back(u);
            adjw[v].push_back(w);
        }
        for(int i=0;i<=n;i++) vis[i] = false;
        dfsa(a);
        for(int i=0;i<=n;i++) vis[i] = false;
        dfsb(b);
        for(int i=1;i<=n;i++){
            adj[i].clear();
            adjw[i].clear();
        }
        bool ok = false;
        for(auto it = valsa.begin(); it != valsa.end(); ++it){
            if(valsb.count(*it)) ok = true;
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
