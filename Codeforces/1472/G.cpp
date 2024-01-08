#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int d[N], ans[N];
int vis[N];
void dfs(int u){
    vis[u] = true;
    ans[u] = d[u];
    for(auto v : adj[u]){
        if(d[v] > d[u]){
            if(!vis[v]) dfs(v);
            ans[u] = min(ans[u], ans[v]);
        }else{
            ans[u] = min(ans[u], d[v]);
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
        int n, m;
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            d[i] = INF_INT;
            ans[i] = INF_INT;
            adj[i].clear();
            vis[i] = 0;
        }
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        d[1] = 0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(auto v : adj[u]){
                if(d[v] > d[u] + 1){
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        dfs(1);
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
