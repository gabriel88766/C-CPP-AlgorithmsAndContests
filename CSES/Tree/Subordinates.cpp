#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
bool visited[N];
int sz[N];

void dfs(int u, int p){
    //sz[u]++;
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs(v, u);
            sz[u] += sz[v] + 1;
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
    for(int i=2;i<=n;i++){
        int a;
        cin >> a;
        adj[a].push_back(i);
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++) cout << sz[i] << " ";
}
