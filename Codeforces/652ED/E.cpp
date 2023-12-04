#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
int p[N], sz[N];
void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
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
}
vector<int> adj[N], adj2[N];
vector<int> adjC[N];
int dfs_low[N], dfs_num[N], cnt = 0;
int par[N];

vector<pair<int,int>> bdg;
void dfs(int u, int p = -1){ //connected undirected graph
    dfs_low[u] = dfs_num[u] = ++cnt;
    for(auto v : adj[u]){
        if(p == v) continue;
        if(!dfs_num[v]){
            dfs(v, u);
            if(dfs_low[v] > dfs_num[u]) bdg.emplace_back(u, v);
            else unite(u, v);
        }
        dfs_low[u] = min(dfs_low[v], dfs_low[u]);
    }
}

void dfs2(int u, int p = -1){
    par[u] = p;
    for(auto v : adj2[u]){
        if(v != p){
            dfs2(v, u);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, C;
        cin >> a >> b >> C;
        adj[a].push_back(b);
        adj[b].push_back(a);
        adjC[a].push_back(C);
        adjC[b].push_back(C);
    }
    int a, b;
    cin >> a >> b;
    dfs(1);
    for(auto [u, v] : bdg){
        adj2[get(u)].push_back(get(v));
        adj2[get(v)].push_back(get(u));
    }
    dfs2(get(a));
    set<int> nums;
    int cur = get(b);
    nums.insert(cur);
    while(cur != get(a)){
        cur = par[cur];
        nums.insert(cur);
    }
    bool ok = false;
    for(int u=1;u<=n;u++){
        if(!nums.count(get(u))) continue;
        for(int v=0;v<adj[u].size();v++){
            if(!nums.count(get(adj[u][v]))) continue;
            if(adjC[u][v]) ok = true;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
