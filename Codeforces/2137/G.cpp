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
        int n, m, q;
        cin >> n >> m >> q;
        //initially, everything is win!!
        vector<vector<int>> adj(n+1), inv(n+1);
        vector<int> cnt(n+1);
        for(int i=1;i<=m;i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            inv[v].push_back(u);
        }
        for(int i=1;i<=n;i++) cnt[i] = adj[i].size();
        vector<vector<bool>> vis(n+1, vector<bool>(2)); //0 is cry, 1 is River!
        for(int i=1;i<=q;i++){
            int tq, u;
            cin >> tq >> u;
            if(tq == 1){
                if(vis[u][0] && vis[u][1]) continue; //nothing to do;
                else{
                    queue<pair<int, int>> qp;
                    if(!vis[u][0]){
                        vis[u][0] = true;
                        qp.push({u, 0});
                    }
                    if(!vis[u][1]){
                        vis[u][1] = true;
                        qp.push({u, 1});
                    }
                    while(qp.size()){
                        auto [u, x] = qp.front();
                        qp.pop();
                        if(x == 0){
                            //mark all inv, 1
                            for(auto v : inv[u]){
                                if(!vis[v][x^1]){
                                    vis[v][x^1] = true;
                                    qp.push({v, x^1});
                                }
                            }
                        }else{
                            //mark all inv with all edges marked
                            for(auto v : inv[u]){
                                cnt[v]--;
                                if(cnt[v] == 0){
                                    vis[v][x^1] = true;
                                    qp.push({v, x^1});
                                }
                            }
                        }
                    }
                }
            }else{
                if(vis[u][0]) cout << "NO\n";
                else cout << "YES\n";
            }
        }
    }
}
