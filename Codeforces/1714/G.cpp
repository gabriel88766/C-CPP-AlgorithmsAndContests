#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int n;
vector<int> adj[N];
ll a[N], b[N], ps[N], ans[N], S = 0;

void dfs(int u, int p, int d){
    if(u != 1) ps[d] = ps[d-1] + b[u];
    ans[u] = prev(lower_bound(ps, ps+d+1, S+1)) - ps;
    for(auto v : adj[u]){
        if(v != p){
            S += a[v];
            dfs(v, u, d+1);
            S -= a[v];
        }
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
        cin >> n;
        for(int i=2;i<=n;i++){
            int k1,k2,k3;
            cin >> k1 >> k2 >> k3;
            adj[i].push_back(k1);
            adj[k1].push_back(i);
            a[i] = k2;
            b[i] = k3;
        }
        dfs(1, -1, 0);
        for(int i=2;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
        for(int i=1;i<=n;i++) {a[i] = b[i] = ans[i] = 0; adj[i].clear();}
        S = 0;
    }
}
