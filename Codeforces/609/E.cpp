#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;
typedef pair<pair<int,int>,pair<int,int>> piii;

// Lowest Common Ancestor <O(nlogn), O(logn)> // tested in J - 2014
const int N = 2e5+3, M = 20;
int anc[M][N], h[N], Wmax[M][N],n,m;
char isInTree[N];
vector<pair<int,int>> adj[N];

// TODO: Calculate h[u] and set anc[0][u] = parent of node u for each u
void dfs(int u=1,int dist=0,int p=1){
    h[u] = dist;
    anc[0][u] = p;
    for(auto v : adj[u]){
        if( v.st != p){
            Wmax[0][v.st] = v.nd;
            dfs(v.st,dist+1,u);
        }
    }
}

void build(){
dfs();
for (int i = 1; i < M; ++i)
  for (int j = 1; j <= n; ++j)
    anc[i][j] = anc[i-1][anc[i-1][j]], Wmax[i][j] = max(Wmax[i-1][j],Wmax[i-1][anc[i-1][j]]);
}
// query
int lca(int u, int v) {
   int maxc = -5;
  if (h[u] < h[v]) swap(u, v);
  for (int i = M-1; i >= 0; --i) if (h[u]-(1<<i) >= h[v])
    maxc = max(maxc,Wmax[i][u]), u = anc[i][u];

  if (u == v) return maxc;

  for (int i = M-1; i >= 0; --i) if (anc[i][u] != anc[i][v])
    maxc = max(maxc,max(Wmax[i][u],Wmax[i][v])), u = anc[i][u], v = anc[i][v];
  return max(maxc,max(Wmax[0][u],Wmax[0][v]));
}
// Disjoint Set Union / Union-find , tested 25D
int par[N], sz[N]; //

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return;
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
}

// Kruskal - MST O(ElogE)
vector<piii> edges;
// + Union-find
long long int kruskal(){
    sort(edges.begin(), edges.end());
    long long int cost = 0;
    for (int i=0;i<edges.size();i++)
      if (find(edges[i].nd.st) != find(edges[i].nd.nd)){
        adj[edges[i].nd.st].push_back({edges[i].nd.nd,edges[i].st.st});
        adj[edges[i].nd.nd].push_back({edges[i].nd.st,edges[i].st.st});
        isInTree[edges[i].st.nd]=true;
        unite(edges[i].nd.st, edges[i].nd.nd), cost += edges[i].st.st;
      }
    return cost;
}

void init(){
    for(int i=0;i<N;i++){
        sz[i]=1;
        par[i]=i;
    }
}

bool mysort(piii a,piii b){
    return a.st.nd < b.st.nd;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    init();
    long long int totalcost;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        edges.push_back({{w,i},{a,b}});
    }
    totalcost = kruskal();
    build();
    sort(edges.begin(),edges.end(),mysort);
    for(int i=0;i<m;i++){
        if(isInTree[i]){
            cout << totalcost << "\n";
        }else{
            cout << totalcost + edges[i].st.st - lca(edges[i].nd.st,edges[i].nd.nd) << "\n";
        }
    }

}