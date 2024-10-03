#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N], adj2[N];
int x[N];
int vis[N];

void dfs1(int u, int p = 0){ //dfs tree as spanning tree
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v]){
            adj2[u].push_back(v);
            dfs1(v, u);
        }
    }
}
int rt = -1;
vector<int> ans;
void dfs2(int u){
    ans.push_back(u);
    x[u] ^= 1;
    for(auto v: adj2[u]){
        dfs2(v);
        ans.push_back(u);
        x[u] ^= 1;
    }
    for(auto v : adj2[u]){
        if(x[v] == 1){
            x[v] ^= 1;
            x[u] ^= 1;
            ans.push_back(v);
            ans.push_back(u);
        }
    }
    if(u == rt){
        if(x[u] == 1){
            int v = adj2[u][0];
            ans.push_back(v);
            ans.push_back(u);
            ans.push_back(v);
        }
    }

}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cin >> x[i];
        if(x[i] == 1){
            rt = i;
            cnt++;
        }
    } 
    if(rt == -1){
        cout << "0\n";
        return 0;
    }
    dfs1(rt, 0);
    for(int i=1;i<=n;i++){
        if(x[i] == 1 && vis[i] == 0){
            cout << "-1\n";
            return 0;
        }
    }
    if(adj2[rt].size() == 0){
        assert(cnt == 1);
        cout << "1\n" << rt << "\n";
        return 0;
    }
    dfs2(rt);
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}
