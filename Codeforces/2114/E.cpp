#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll mx[N], mn[N], val[N];
vector<int> adj[N];
void dfs(int u, int p = 0){
    if(p == 0) mn[u] = mx[u] = val[u];
    else{
        mn[u] = min(val[u] - mx[p], val[u]);
        mx[u] = max(val[u] - mn[p], val[u]);
    }
    for(auto &v : adj[u]){
        if(v != p) dfs(v, u);
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
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
            mx[i] = -INF_LL;
            mn[i] = INF_LL;
            adj[i].clear();
            cin >> val[i];
        }
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0);
        for(int i=1;i<=n;i++) cout << mx[i] << " ";
        cout << "\n";
    }
}
