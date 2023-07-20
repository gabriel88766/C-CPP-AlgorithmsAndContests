#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll h[N];
bool vis[N];
vector<int> adj[N];

void dfs(int u){
    int cnt = 0;
    vis[u] = true;
    for(auto v : adj[u]){
        if(!vis[v]){
            cnt++;
            dfs(v);
            h[u] += h[v];
        }
    }
    if(cnt == 0) h[u] = 1;
}
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
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1);
        int q;
        cin >> q;
        while(q--){
            int a, b;
            cin >> a >> b;
            cout << h[a]*h[b] << "\n";
        }
        for(int i=1;i<=n;i++){
            h[i] = 0;
            adj[i].clear();
            vis[i] = false;
        }
    }
}   
