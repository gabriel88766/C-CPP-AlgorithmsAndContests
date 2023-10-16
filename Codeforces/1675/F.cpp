#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k, x, y;
        cin >> n >> k;
        cin >> x >> y;
        set<int> v;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<k;i++){
            int aux;
            cin >> aux;
            v.insert(aux);
        }
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> par(n+1, 0);
        function<void(int,int)> dfs_path = [&](int u, int p){
            par[u] = p;
            for(auto v : adj[u]){
                if(v != p){
                    dfs_path(v, u);
                }
            }
        };
        dfs_path(x, -1);
        int cur = y;
        set<int> path;
        path.insert(y);
        while(cur != x){
            cur = par[cur];
            path.insert(cur);
        }
        int ans = path.size() - 1;
        function<bool(int,int)> dfs = [&](int u, int p){
            int curs = 0;
            bool ok = false;
            for(auto v : adj[u]){
                if(v != p && !path.count(v)){
                    if(dfs(v, u)){
                         ans += 2;
                         ok = true;
                    }
                }
            }
            if(v.count(u)) ok = true;
            return ok;
        };
        for(auto v : path) dfs(v, -1);
        cout << ans << "\n";
    }
}
