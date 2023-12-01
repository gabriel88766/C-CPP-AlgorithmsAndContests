#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3;
ll dp[N];
vector<int> adj[N];
ll val[N];
ll ans = 0;
void dfs(int u, int p){
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
        }
    }
    if(u != 1){
        if(adj[u].size() == 1){
            dp[u] = val[u];
        }else if(adj[u].size() == 2){
            for(auto v : adj[u]){
                if(v != p){
                    dp[u] = max(dp[v], val[u]);
                    ans = max(ans, dp[v] + val[u]);
                }
            }
        }else{
            //0 child
            dp[u] = val[u];
            //1 child
            for(auto v : adj[u]){
                if(v != p){
                    dp[u] = max(dp[u], dp[v]);
                    ans = max(ans, dp[v] + val[u]);
                }
            }
            //2 or more children
            int c = 0;
            ll sum = 0; //val[u]
            for(auto v : adj[u]){
                if(v != p){
                    if(dp[v] >= 0){
                        sum += dp[v];
                        c++;
                    }
                }
            }
            if(c){
                if(c == 1){
                    ll maxv = -INF_LL;
                    for(auto v : adj[u]){
                        if(v != p){
                            if(dp[v] < 0){
                                maxv = max(maxv, dp[v]);
                            }
                        }
                    }
                    sum += maxv;
                    c++;
                }
                dp[u] = val[u] + sum;
                if(c == 2){
                    ans = max(ans, sum);
                }else{
                    ans = max(ans, dp[u]);
                }
            }
        }
    }else{
        if(adj[u].size() == 1){
            dp[u] = dp[adj[u][0]] + val[u];
            ans = max(ans, dp[u]);
        }else if(adj[u].size() == 2){
            dp[u] = max(dp[u], dp[adj[u][0]] + val[u]);
            dp[u] = max(dp[u], dp[adj[u][1]] + val[u]);
            dp[u] = max(dp[u], dp[adj[u][0]] + dp[adj[u][1]]);
            ans = max(ans, dp[u]);
        }else{
            //1 child
            for(auto v : adj[u]){
                ans = max(ans, val[u] + dp[v]);
            }
            //2 or more children
            vector<ll> alld;
            for(auto v: adj[u]){
                alld.push_back(dp[v]);
            }
            sort(alld.begin(), alld.end(), greater<ll>());
            ans = max(ans, alld[0] + alld[1]);
            ll sum = 0;
            int c = 0;
            for(auto x : alld){
                if(x >= 0){
                    c++;
                    sum += x;
                }else break;
            }
            if(c > 2){
                ans = max(ans, sum + val[u]);
            }
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
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
             cin >> val[i];
             ans = max(ans, val[i]);
        }
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0);
        cout << ans << "\n";
        for(int i=1;i<=n;i++){
            adj[i].clear();
            val[i] = 0;
            dp[i] = 0;
            ans = 0;
        }
    }
}
