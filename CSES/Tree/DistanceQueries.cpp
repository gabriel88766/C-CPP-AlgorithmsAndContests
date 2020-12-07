#include <bits/stdc++.h>

using namespace std;


const int N = 2e5+3, M = 20;
int anc[M][N], h[N], rt=1, n, q;
vector<int> adj[N];

void dfs(int u=rt,int dist=0,int p=-1){
    h[u] = dist;
    anc[0][u] = p;
    for(auto v : adj[u]){
        if( v != p) dfs(v,dist+1,u);
    }
}


void build(){
dfs();
anc[0][rt] = rt;
for (int i = 1; i < M; ++i)
  for (int j = 1; j <= n; ++j)
    anc[i][j] = anc[i-1][anc[i-1][j]];
}

int lca(int u, int v) {
  int cost=0;
  if (h[u] < h[v]) swap(u, v);
  for (int i = M-1; i >= 0; --i) if (h[u]-(1<<i) >= h[v])
    u = anc[i][u], cost+=(1<<i);

  if (u == v) return cost;

  for (int i = M-1; i >= 0; --i) if (anc[i][u] != anc[i][v])
    u = anc[i][u], v = anc[i][v],cost+= (1<<(i+1));
  return cost+2;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for(int i=2;i<=n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build();
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        cout << lca(a,b) << "\n";
    }

}


