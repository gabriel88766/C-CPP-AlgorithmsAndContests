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
        if(n == 2){
            int a, b;
            cin >> a >> b;
            cout << "NO\n";
            continue;
        }
        vector<vector<int>> adj(n+1);
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int rt = -1;
        function<void(int, int, int)> dfs = [&](int u, int p, int lst){
            if(u == rt){
                cout << adj[u][0] << " " << rt << "\n";
                cout << rt << " " << adj[u][1] << "\n";
                //for adj[u][0] must be -> and adj[u][1] must be <-
                dfs(adj[u][0], u, 1);
                dfs(adj[u][1], u, 0);
                return;
            }


            for(auto v : adj[u]){
                if(v != p){
                    if(lst == 1){
                        cout << u << " " << v << "\n";
                    }else{
                        cout << v << " " << u << "\n";
                    }
                    dfs(v, u, lst ^ 1);
                }
            }
        };
        
        for(int i=1;i<=n;i++){
            if(adj[i].size() == 2){
                rt = i;
                break;
            }
        }
        if(rt == -1) cout << "NO\n";
        else{
            cout << "YES\n";
            dfs(rt, 0, 0);
        }
    }
}
