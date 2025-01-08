#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int h[N], par[N];
void dfs(int u = 1, int p = 0){
    par[u] = p;
    h[u] = h[p] + 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    h[0] = -1;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=n;i++){
        if(h[i] > 2) pq.push({h[i], i});
    }
    int ans = 0;
    while(pq.size()){
        auto [d, u] = pq.top();
        pq.pop();
        if(h[u] > 2){
            ans++;
            int x = par[u];
            h[x] = 1;
            for(auto v : adj[x]){
                h[v] = 2;
            }
        }
    }
    cout << ans << "\n";
}   
