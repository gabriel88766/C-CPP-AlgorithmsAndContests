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
        int n;
        cin >> n;
        vector<vector<ll>> adj(n+1), adjt(n+1);
        vector<ll> dist(n+1, INF_LL);
        for(int i=0;i<n-1;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adjt[a].push_back(i);
            adj[b].push_back(a);
            adjt[b].push_back(i);
        }
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        pq.push({0, 1});
        dist[1] = 0;
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(int i=0;i<adj[u].size();i++){
                int v = adj[u][i];
                ll t = adjt[u][i];
                ll ds;
                if(t >= d % (n-1)) ds = t - d % (n-1);
                else ds = t + n-1 - d % (n-1);
                if(ds + dist[u] < dist[v]){
                    dist[v] = dist[u] + ds;
                    pq.push({dist[v], v});
                }
            }
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ans = max(ans, dist[i]/(n-1)+1);
        }
        cout << ans << "\n";
    }
}
