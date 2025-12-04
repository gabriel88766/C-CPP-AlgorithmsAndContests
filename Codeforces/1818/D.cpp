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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        bool ok = false;
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(adj[i].size() >= 4){
                vector<int> d(n+1, INF_INT);
                vector<int> par(n+1, -1);
                function<void(int)> dfs = [&](int u){
                    for(auto v : adj[u]){
                        if(par[v] == -1 && par[u] != v){
                            par[v] = u;
                            if(v != i) dfs(v);
                        }
                    }
                };
                dfs(i);
                if(par[i] != -1){
                    ok = true;
                    vector<int> path;
                    path.push_back(i);
                    do{
                        path.push_back(par[path.back()]);
                    }while(path.back() != i);
                    //not ready yet!
                    for(int i=2;i<path.size() - 1;i++){
                        bool hn = false;
                        for(auto v : adj[path[i]]){
                            if(v == path[0]){
                                hn = true;
                            }
                        }
                        if(hn){
                            while(path.size() != i + 1) path.pop_back();
                            path.push_back(path[0]);
                            break;
                        }
                    }




                    cout << "YES\n" << 1 + path.size() << "\n";
                    int n1 = path[1];
                    int n2 = path[path.size() - 2];
                    assert(path.size() >= 4);
                    vector<int> an;
                    for(auto v : adj[i]){
                        if(v != n1 && v != n2) an.push_back(v);
                    }
                    assert(an.size() >= 2);
                    cout << i << " " << an[0] << "\n";
                    cout << i << " " << an[1] << "\n";
                    for(int i=1;i<path.size();i++){
                        cout << path[i-1] << " " << path[i] << "\n";
                    }
                    break;
                }
            }
        }
        if(!ok){
            cout << "NO\n";
        }
    }
}
