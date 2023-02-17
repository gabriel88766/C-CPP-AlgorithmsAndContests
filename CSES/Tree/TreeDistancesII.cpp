#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
bool vis[N];
ll sz[N], sd[N];
int n;

void dfs_1(int u){
    vis[u] = true;
    sz[u] = 1;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs_1(i);
            sz[u] += sz[i];
            sd[u] += (sd[i] + sz[i]);
        }
    }
}
void dfs_2(int u, int p){
    if(p != -1){
        sd[u] = sd[p] + (n - 2*sz[u]);
    }
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs_2(i, u);
        }
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    cin >> n;
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs_1(1);
    for(int i=1;i<=n;i++) vis[i] = false;
    dfs_2(1, -1);
    for(int i=1;i<=n;i++) cout << sd[i] << " ";
}
