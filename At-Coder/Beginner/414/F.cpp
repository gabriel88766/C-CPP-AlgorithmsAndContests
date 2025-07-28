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
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n+1);
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //allowed moves:
        //up x down y (x + y) == k
        //down k
        //up k
        vector<vector<int>> vis(n+1, vector<int>(k+1)); //visited up x, only two times.
        vector<int> h(n+1), sub(n+1), ord(n+1), invord(n+1);
        vector<vector<int>> hh(n+k + 1);
        vector<vector<int>> par(n+1, vector<int>(k+1));
        int cnt = 0;
        h[0] = -1;
        function<void(int, int)> dfs = [&](int u, int p){
            ord[u] = ++cnt;
            invord[cnt] = u;
            sub[u] = 1;
            h[u] = h[p] + 1;
            par[u][1] = p;
            hh[h[u]].push_back(ord[u]);
            for(auto v : adj[u]){
                if(v != p){
                    dfs(v, u);
                    sub[u] += sub[v];
                }
            }
        };
        dfs(1, 0);
        for(int i=2;i<=k;i++){
            for(int j=1;j<=n;j++){
                par[j][i] = par[par[j][i-1]][1];
            }
        }
        vector<int> d(n+1, INF_INT);
        queue<int> q;
        q.push(1);
        d[1] = 0;
        while(q.size()){
            int u = q.front();
            q.pop();
            //up k
            int du = par[u][k];
            if(du != 0 && d[du] > d[u] + 1){
                d[du] = d[u] + 1;
                q.push(du);
            }
            auto fs = lower_bound(hh[h[u] + k].begin(), hh[h[u] + k].end(), ord[u]);
            while(fs != hh[h[u] + k].end() && *fs <= ord[u] + sub[u] - 1){
                int cv = invord[*fs];
                if(d[cv] > d[u] + 1){
                    d[cv] = d[u] + 1;
                    q.push(cv);
                }
                fs++;
            }
            for(int j=1;j<k;j++){
                int ct = j == 1 ? u : par[u][j-1];
                int cp = par[u][j];
                if(cp && vis[cp][k-j] != -1){
                    if(vis[cp][k-j] == 0) vis[cp][k-j] = ct;
                    else if(vis[cp][k-j] == ct) continue;
                    else vis[cp][k-j] = -1;
                    auto fs = lower_bound(hh[h[cp] + k-j].begin(), hh[h[cp] + k - j].end(), ord[cp]);

                    while(fs != hh[h[cp] + k-j].end() && *fs <= ord[cp] + sub[cp] - 1){
                        if(*fs < ord[ct] || *fs >= ord[ct] + sub[ct]){
                            int cv = invord[*fs];
                            if(d[cv] > d[u] + 1){
                                d[cv] = d[u] + 1;
                                q.push(cv);
                            }
                        }
                        fs++;
                    }
                }
            }
        }



        for(int i=2;i<=n;i++){
            if(d[i] == INF_INT) cout << "-1 ";
            else cout << d[i] << " ";
        }
        cout << "\n";
    }
}
