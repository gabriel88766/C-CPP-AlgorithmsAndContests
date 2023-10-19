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
        int n, rt;
        cin >> n;
        vector<vector<int>> adj(n+1), path(n+1);
        for(int i=1;i<=n;i++){
            int p;
            cin >> p;
            if(p == i) rt = i;
            else adj[p].push_back(i);
        }
        int cnt = 1;
        function<void(int,int)> dfs = [&](int u, int gp){
            path[gp].push_back(u);
            for(int i=0;i<adj[u].size(); i++){
                if(i) dfs(adj[u][i], ++cnt);
                else dfs(adj[u][i], gp);
            }
        };
        dfs(rt, 1);
        cout << cnt << "\n";
        for(int i=1;i<=cnt;i++){
            cout << path[i].size() << "\n";
            for(auto x : path[i]) cout << x << " ";
            cout << "\n";
        }
        cout << "\n";
    }
}
