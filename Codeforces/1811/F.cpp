#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
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
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        size_t dg = 0;
        for(int i=1;i<=n;i++) dg = max(dg, adj[i].size());
        vector<int> nds;
        for(int i=1;i<=n;i++) if(dg == adj[i].size()) nds.push_back(i);
        ll k = nds.size();
        if(k * k == n && dg == 4){
            vector<bool> nd4(n+1, false);
            for(auto x : nds) nd4[x] = true;
            bool ok = true;
            for(auto u : nds){
                int cnt = 0;
                for(auto v : adj[u]){
                    if(nd4[v]) cnt++;
                }
                if(cnt != 2) ok = false;
            }
            vector<int> path;
            path.push_back(nds[0]);
            vector<bool> vis(n+1, false);
            vis[nds[0]] = true;
            while(true){
                int nv = -1;
                for(auto v : adj[path.back()]){
                    if(vis[v] == false && nd4[v] == true){
                        nv = v;
                    }
                }
                if(nv != -1){
                    vis[nv] = true;
                    path.push_back(nv);
                }else break;
            }
            if(path.size() != k) ok = false;
            for(int i=1;i<=n;i++){
                if(nd4[i] == false && adj[i].size() != 2) ok = false;
            }
            if(ok){
                //check each path;
                for(auto u : nds){
                    vector<int> path;
                    function<void(int)> dfs = [&](int u){
                        path.push_back(u);
                        for(auto v : adj[u]){
                            if(!vis[v]){
                                vis[v] = true;
                                dfs(v);
                            }
                        }
                    };
                    dfs(u);
                    if(path.size() != k) ok = false;
                    else{
                        int x = path.back();
                        if(adj[x][0] != u && adj[x][1] != u) ok = false;
                    }
                }   
                if(ok) cout << "YES\n";
                else cout << "NO\n";
            }else cout << "NO\n";
        }else cout << "NO\n";


        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
