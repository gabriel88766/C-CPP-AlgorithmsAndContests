#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<pair<int, int>> adj[N];
bool ok[N];
//cout << fixed << setprecision(6)
int n, m, l, s, t;
void dfs(int u, int x, int val){
    if(x == l){
        if(val >= s && val <= t) ok[u] = true;
        return;
    }
    for(auto [v, c] : adj[u]){
        dfs(v, x+1, val+c);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> m >> l >> s >> t;
    for(int i=1;i<=m;i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }
    dfs(1, 0, 0);
    for(int i=1;i<=n;i++){
        if(ok[i]) cout << i << " ";
    }
    cout << "\n";
}   
