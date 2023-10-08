#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int dfs_low[N], dfs_num[N], cnt = 0;

vector<pair<int,int>> bdg;
void dfs(int u, int p = -1){ //connected undirected graph
    dfs_low[u] = dfs_num[u] = ++cnt;
    for(auto v : adj[u]){
        if(p == v) continue;
        if(!dfs_num[v]){
            dfs(v, u);
            if(dfs_low[v] > dfs_num[u]) bdg.emplace_back(u, v);
        }
        dfs_low[u] = min(dfs_low[v], dfs_low[u]);
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    set<int> st;
    for(auto x : bdg){
        if(adj[x.first].size() != 1) st.insert(x.first);
        if(adj[x.second].size() != 1) st.insert(x.second);
    }
    cout << st.size() << "\n";
    for(auto x : st) cout << x << " ";
}
