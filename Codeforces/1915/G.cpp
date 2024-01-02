#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct cond{
    ll u, s, d;
    bool operator< (const cond &b) const {
        return d > b.d;
    }
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> adj(n+1), adjw(n+1);
        for(int i=0;i<m;i++){
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back(b);
            adjw[a].push_back(w);
            adj[b].push_back(a);
            adjw[b].push_back(w);
        }
        vector<ll> ss(n+1);
        for(int i=1;i<=n;i++) cin >> ss[i];
        vector<vector<ll>> dp(n+1, vector<ll>(1001, INF_LL));
        dp[1][ss[1]] = 0;
        priority_queue<cond> pq;
        pq.push({1, ss[1], 0});
        while(!pq.empty()){
            auto [u, s, d] = pq.top();
            pq.pop();
            if(d > dp[u][s]) continue;
            for(int i=0;i<adj[u].size();i++){
                auto v = adj[u][i];
                auto w = adjw[u][i];
                ll nc = min(s, ss[v]);
                if(dp[v][nc] > d + s * w){
                    dp[v][nc] = d + s * w;
                    pq.push({v, nc, dp[v][nc]});
                }
            }
        }
        ll ans = INF_LL;
        for(int i=1;i<=1000;i++) ans = min(ans, dp[n][i]);
        cout << ans << "\n";
    }
}