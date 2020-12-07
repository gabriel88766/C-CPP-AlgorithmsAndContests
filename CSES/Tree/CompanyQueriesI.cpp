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

int query(int u,int dist){
    for (int i = M-1; i >= 0; --i) if (dist&(1<<i))
        u = anc[i][u], dist &= (~(1<<i));

    return u;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for(int i=2;i<=n;i++){
        int aux;
        cin >> aux;
        adj[aux].push_back(i);
        adj[i].push_back(aux);
    }
    build();
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        int aux = query(a,b-1);
        if(aux==1) cout << "-1\n";
        else cout << query(aux,1) << "\n";
    }

}
