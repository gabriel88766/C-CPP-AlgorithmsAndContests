#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
bool vis[N];
void dfs(int u){
    vis[u] = true;
    for(auto x : adj[u]){
        if(!vis[x]) dfs(x);
    }
}

int p[N], sz[N], a[N];
set<pair<int,int>> adjl[N];

void init(int n){
    for(int i=1;i<=n;i++) {
        p[i] = i; sz[i] = 1;
        adjl[i].clear();
        for(auto v : adj[i]){
            adjl[i].insert({a[v], v});
        }
    }
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    for(auto x : adjl[b]){
        adjl[a].insert(x);
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
        int n, m;
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=0;i<m;i++){
            int u,v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        bool ok = true;
        dfs(1);
        vector<int> ini;
        for(int i=1;i<=n;i++) if(!vis[i]) ok = false;
        if(!ok){
            cout << "NO\n";
            for(int i=1;i<=n;i++) { adj[i].clear(); vis[i] = false;}
            continue;
        }
        init(n);

        for(int i=1;i<=n;i++){
            if(a[i] == 0){
                ini.push_back(i);
            }
        }
        
        for(auto x : ini){
            while(adjl[get(x)].size() && adjl[get(x)].begin()->first <= sz[get(x)]){
                auto val = *adjl[get(x)].begin();
                adjl[get(x)].erase(val);
                unite(val.second, get(x));
            }
        }


        if(sz[get(1)] != n) ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
        for(int i=1;i<=n;i++) { adj[i].clear(); vis[i] = false;}
    }
}
