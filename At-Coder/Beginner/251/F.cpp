#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
vector<pair<int,int>> t1, t2;
int vis[N];
void dfs(int u){
    vis[u] = true;
    for(auto v : adj[u]){
        if(!vis[v]){
            t1.push_back({u, v});
            dfs(v);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    queue<int> q;
    q.push(1);
    for(int i=1;i<=n;i++) vis[i] = false;
    vis[1] = true;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(!vis[v]){
                t2.push_back({u, v});
                vis[v] = true;
                q.push(v);
            }
        }
    }
    for(auto [a, b] : t1) cout << a << " " << b << "\n";
    for(auto [a, b] : t2) cout << a << " " << b << "\n";
}
