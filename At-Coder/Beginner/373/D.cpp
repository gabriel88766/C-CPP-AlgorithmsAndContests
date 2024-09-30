#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll ans[N];
int vis[N];
vector<int> adj[N], adjw[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adjw[a].push_back(w);
        adj[b].push_back(a);
        adjw[b].push_back(-w);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = true;
            ans[i] = 0;
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                for(int i=0;i<adj[u].size();i++){
                    int v = adj[u][i];
                    int w = adjw[u][i];
                    if(!vis[v]){
                        vis[v] = true;
                        q.push(v);
                        ans[v] = ans[u] + w;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}
