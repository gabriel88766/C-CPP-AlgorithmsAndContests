#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
vector<int> adj[N];
int ngen[N];
int ans = 0;
void dfs(int u){
    if(ngen[u] >= 0) ans++;
    for(auto v : adj[u]){
        ngen[v] = max(ngen[v], ngen[u] - 1);
        dfs(v);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(ngen, 0xFF, sizeof(ngen));
    int n, m;
    cin >> n >> m;
    for(int i=2;i<=n;i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for(int i=1;i<=m;i++){
        int x, y;
        cin >> x >> y;
        ngen[x] = max(ngen[x], y);
    }
    dfs(1);
    cout << ans << "\n";
}
