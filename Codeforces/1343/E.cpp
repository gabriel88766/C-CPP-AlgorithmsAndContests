#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> bfs(vector<vector<int>> &adj, int src){
    vector<int> d(adj.size(), INF_INT);
    d[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return d;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;
        vector<int> p(m+1);
        vector<ll> ps(m+1, 0);
        for(int i=1;i<=m;i++){
             cin >> p[i];
        }
        sort(p.begin()+1, p.end());
        for(int i=1;i<=m;i++){
            ps[i] = ps[i-1] + p[i];
        }
        vector<vector<int>> adj(n+1);
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        auto d1 = bfs(adj, a);
        auto d2 = bfs(adj, b);
        auto d3 = bfs(adj, c);
        ll ans = INF_LL;
        for(int i=1;i<=n;i++){
            // a -> x, x-> b, b -> x, x -> c
            int l1 = d2[i];
            int l2 = d1[i] + d2[i] + d3[i];
            if(l2 > m) continue;
            ans = min(ans, ps[l1] + ps[l2]);
        }
        cout << ans << "\n";
    }
}
 