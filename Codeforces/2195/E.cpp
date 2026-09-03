#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
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
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        adj[0].push_back(1);
        for(int i=1;i<=n;i++){
            int a, b;
            cin >> a >> b;
            if(a != 0){
                adj[i].push_back(a);
                adj[i].push_back(b);
            }
        }
        vector<int> sub(n+1);
        vector<ll> sum(n+1);
        function<void(int)> dfs = [&](int u){
            sub[u] = 1;
            for(auto v : adj[u]){
                dfs(v);
                sub[u] += sub[v];
            }
            if(u != 0) sum[u] = 2 * sub[u] - 1;
            else sum[u] = 0;
        };
        function<void(int, int)> dfs2 = [&](int u, int p){
            sum[u] += sum[p];
            for(auto v : adj[u]) dfs2(v, u);
        };
        dfs(0);
        dfs2(0, 0);
        for(int i=1;i<=n;i++) cout << sum[i] % MOD << " ";
        cout << "\n";
    }
}
