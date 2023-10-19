#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
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
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vector<vector<int>> adj(n+1);
        vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
        vector<set<int>> sd(n+1);
        vector<int> d(n+1, INF_INT);
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            sd[d[u]].insert(u);
            q.pop();
            for(auto v: adj[u]){
                if(d[v] > d[u] + 1){
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        dp[s][0] = 1;
        for(int i=1;i<=d[t];i++){
            for(auto x : sd[i]){
                for(auto v: adj[x]){
                    if(sd[i-1].count(v)){
                        dp[x][0] = (dp[x][0] + dp[v][0]) % MOD;
                        dp[x][1] = (dp[x][1] + dp[v][1]) % MOD;
                    }
                }
            }
            for(auto x : sd[i]){
                for(auto v: adj[x]){
                    if(sd[i].count(v)){
                        dp[x][1] = (dp[x][1] + dp[v][0]) % MOD;
                    }
                }
            }
        }
        cout << (dp[t][0] + dp[t][1]) % MOD << "\n";

    }
}
