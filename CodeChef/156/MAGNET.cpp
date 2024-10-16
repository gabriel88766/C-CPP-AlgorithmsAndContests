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
            for(int i=1;i<n;i++){
                int a, b;
                cin >> a >> b;
            }
            cout << "-1\n";
        }else{
            vector<vector<int>> adj(n+1);
            vector<int> h(n+1);
            int rt = -1;
            for(int i=1;i<n;i++){
                int a, b;
                cin >> a >> b;
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
            int mxh = 0;
            function<void(int, int)> dfs = [&](int u, int p){
                h[u] = h[p] + 1;
                mxh = max(mxh, h[u]);
                for(auto v : adj[u]){
                    if(v != p){
                        dfs(v, u);
                    }
                }
            }; 
            vector<int> ans;
            function<void(int, int)> solve = [&](int u, int p){
                ans.push_back(u);
                for(auto v : adj[u]){
                    if(v != p){
                        solve(v, u);
                    }
                }
            }; 
            h[0] = -1;
            for(int i=1;i<=n;i++){
                if(adj[i].size() != 1){
                    rt = i;
                    dfs(i, 0);
                    break;
                }
            }
            if(mxh == 1) cout << "-1\n";
            else{
                //I think I can solve.
                if(adj[adj[rt][0]].size() != 1) swap(adj[rt][1], adj[rt][0]);
                solve(rt, 0);
                for(auto x : ans) cout << x << " ";
                cout << "\n";
            }
        }
    }
}
