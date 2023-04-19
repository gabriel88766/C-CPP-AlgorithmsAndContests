#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//O(V+E)
const int N = 1e5+3;
vector<int> adj[N];
vector<ll> adjw[N];
int ans[N];
bool vis[N];

void dfs(int u, ll cd = 0){
    vis[u] = true;
    if(cd % 2) ans[u] = 1;
    else ans[u] = 0;
    for(int i=0;i<adj[u].size(); i++){
        if(!vis[adj[u][i]]){
            dfs(adj[u][i], cd + adjw[u][i]);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adjw[a].push_back(c);
        adj[b].push_back(a);
        adjw[b].push_back(c);
    }
    dfs(1);
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
}
